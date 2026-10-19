#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <algorithm>

// 标准二分查找实现
int BinarySearch(const std::vector<int>& arr, int target) {
    int low = 0, high = static_cast<int>(arr.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void runExperiment() {
    const int testTimes = 100000;   // 每个 n 的测试次数
    const int warmupTimes = 10000;  // 预热次数
    std::mt19937 rng(1339);         // 固定种子

    std::ofstream fout("binary_search_result.csv");
    if (!fout.is_open()) {
        std::cerr << "无法打开 binary_search_result.csv\n";
        return;
    }
    fout << "n,avg_time_ns\n";

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "n\tAverage_Time(ns)\n";

    for (int n = 10; n <= 100; n += 10) {
        // 1. 构建严格递增数组（递增步长至少为 2，保证缝隙间有整数）
        std::vector<int> arr(n);
        int current = 0;
        for (int i = 0; i < n; ++i) {
            current += static_cast<int>(rng() % 5) + 2;   // 步长 ∈ [2,6]
            arr[i] = current;
        }

        // 2. 预先生成 targets
        std::vector<int> targets(testTimes);
        for (int i = 0; i < testTimes; ++i) {
            if (i % 2 == 0) {
                targets[i] = arr[rng() % n];              // 成功
            } else {
                int gap = rng() % (n + 1);                // 失败，均匀落在 n+1 个缝隙
                if (gap == 0) {
                    targets[i] = arr[0] - 1;
                } else if (gap == n) {
                    targets[i] = arr[n - 1] + 1;
                } else {
                    int lo = arr[gap - 1], hi = arr[gap];
                    targets[i] = lo + (hi - lo) / 2;      // 严格落在 (lo, hi) 内部
                }
            }
        }

        // --- CPU 与 Cache 预热 (Warm-up) ---
        long long warmup_sum = 0;
        for (int i = 0; i < warmupTimes; ++i) {
            warmup_sum += BinarySearch(arr, targets[i % testTimes]);
        }

        // 3. 正式计时（仅计算二分查找）
        long long local_sum = 0;
        auto start = std::chrono::steady_clock::now();
        for (int i = 0; i < testTimes; ++i) {
            local_sum += BinarySearch(arr, targets[i]);
        }
        auto end = std::chrono::steady_clock::now();

        // 防止编译器完全优化掉计算过程
        volatile long long sink = local_sum + warmup_sum;
        (void)sink;

        double total_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        double avg_ns   = total_ns / testTimes;

        std::cout << n << "\t" << avg_ns << "\n";
        fout    << n << "," << avg_ns << "\n";
    }

    fout.close();
    std::cout << "\n结果已写入 binary_search_result.csv\n";
}

int main() {
    runExperiment();
    return 0;
}