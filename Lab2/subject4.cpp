#include <iostream>
#include <vector>
using std::vector;

// 给定一个字符串s，找到s中最长的回文字串。回文串就是正着读和反着读都一样的字符串。

char* findFunction(const char* word, int length){

    if (length == 0){
        return "\0";
    }

    // 1. 奇数回文处理：用 vector 记录每个中心对应的长度和起始 index
    vector<int> oddLength(length, 0);
    vector<int> oddIndex(length, 0);

    for (int i = 0; i < length; i++){
        const char* left = word + i;
        const char* right = left;
        oddLength[i] = 1;
        oddIndex[i] = i; // 记录当前回文的起始索引

        // 往两边扩展比较
        while (left > word && right < word + length - 1){
            left--;
            right++;
            if (*left == *right){
                oddLength[i] += 2;
                oddIndex[i]--; // 每向外扩展一层，起始index前移一位
            }
            else {
                break;
            }
        }
    }

    // 2. 偶数回文处理：检测相邻两个字符相等的情况，用 push_back 写入动态数组
    vector<int> evenLength;
    vector<int> evenIndex;

    for (int i = 0; i < length - 1; i++){
        if (word[i] == word[i+1]){
            const char* left = word + i;
            const char* right = word + i + 1;
            int curLen = 2;
            int curIndex = i;

            // 往两边扩展比较
            while (left > word && right < word + length - 1){
                left--;
                right++;
                if (*left == *right){
                    curLen += 2;
                    curIndex--;
                }
                else {
                    break;
                }
            }
            evenLength.push_back(curLen);
            evenIndex.push_back(curIndex);
        }
    }

    // 3. 用循环比较出所有奇数和偶数回文中的最大长度与对应的起始 index
    int maxLen = 0;
    int bestIndex = 0;

    // 比较奇数回文
    for (int i = 0; i < length; i++){
        if (oddLength[i] > maxLen){
            maxLen = oddLength[i];
            bestIndex = oddIndex[i];
        }
    }

    // 比较偶数回文
    for (size_t i = 0; i < evenLength.size(); i++){
        if (evenLength[i] > maxLen){
            maxLen = evenLength[i];
            bestIndex = evenIndex[i];
        }
    }

    // 4. 返回最长回文字符串
    char* result = new char[maxLen + 1];
    for (int i = 0; i < maxLen; i++){
        result[i] = word[bestIndex + i];
    }
    result[maxLen] = '\0'; // 加上字符串结束符

    return result;
}


int main() {
    using namespace std;

    // 测试字符串
    const char* s = "babad"; 
    int length = strlen(s);

    char* longestPalindrome = findFunction(s, length);

    cout << "原字符串: " << s << endl;
    cout << "最长回文子串: " << longestPalindrome << endl;

    delete[] longestPalindrome;

    return 0;
}