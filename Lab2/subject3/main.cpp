#include <iostream>
#include <iomanip>
#include <fstream>   
#include <ctime>
#include <cmath>
#include "subject3.h"
 using namespace std;
using std::cout;

int main() {

    double x = 1.1;
    int n_list[] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90, 100};
    int numOfN = sizeof(n_list) / sizeof(n_list[0]);

    // 打开一个 CSV 文件用于保存数据
    ofstream outFile("algorithm_performance.csv");
    if (!outFile.is_open()) {
        cerr << "错误：无法创建或打开文件！" << endl;
        return 1;
    }

    // 写入 CSV 表头
    outFile << "n,F1a_Iterative,F1b_Recursive,F2a_Iterative,F2b_Recursive\n";

    cout << "=== 正在运行性能测试并写入文件 ===" << endl;

    int repeat = 10000; // 执行次数

    for (int idx = 0; idx < numOfN; ++idx) {
        int n = n_list[idx];

        // 1. 统一生成当前 n 下公式3的系数数组 a
        double* a = new double[n + 1];
        a[0] = 1.0;
        for (int i = 1; i <= n; ++i) {
            a[i] = 1.0 / i;
        }

        double times[4] = {0.0, 0.0, 0.0, 0.0};
        bool overflow[4] = {false, false, false, false};

        // 2. 测试 4 个算法
        for (int alg_id = 0; alg_id < 4; ++alg_id) {
            // 递归法在 n > 50 时容易栈溢出，做安全保护
            if ((alg_id == 1 || alg_id == 3) && n > 50) {
                overflow[alg_id] = true;
                continue;
            }

            clock_t start = clock();
            for (int k = 0; k < repeat; ++k) {
                if (alg_id == 0) {
                    volatile double r = F1a(n, a, x); (void)r;
                } else if (alg_id == 1) {
                    volatile double r = F1b(n, a, x); (void)r;
                } else if (alg_id == 2) {
                    volatile double r = F2a(n, a, x); (void)r;
                } else if (alg_id == 3) {
                    volatile double r = F2b(n, a, x); (void)r;
                }
            }
            clock_t end = clock();
            times[alg_id] = (double)(end - start) / CLOCKS_PER_SEC / repeat;
        } 

        // 3. 写入 CSV 行数据（如果溢出，写入 -1 方便画图过滤）
        outFile << n << ","
                << times[0] << ","
                << (overflow[1] ? -1 : times[1]) << ","
                << times[2] << ","
                << (overflow[3] ? -1 : times[3]) << "\n";

        delete[] a;
    }

    outFile.close();
    cout << "测试完成！数据已成功写入 'algorithm_performance.csv'。" << endl;
    return 0;
}