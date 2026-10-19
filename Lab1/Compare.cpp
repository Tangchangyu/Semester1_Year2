//----题目二---//
//做成三个运算符重载？
//做成一个比较函数返回枚举类型？
#include <iostream>

enum class COMPARE {
    BIGGER,
    SMALLER,
    EQUAL
};

COMPARE Compare(int a[], int b[], int n, int m) {
    int top = 0;
    if (n < m) top = n;
    else       top = m;

    for (int i = 0; i < top; i++) {
        if (a[i] < b[i]) return COMPARE::SMALLER;
        else if (a[i] > b[i]) return COMPARE::BIGGER;
    }

    if (n < m) return COMPARE::SMALLER;
    else if (n > m) return COMPARE::BIGGER;
    else return COMPARE::EQUAL;
}

const char* toStr(COMPARE c) {
    switch (c) {
        case COMPARE::SMALLER: return "<";
        case COMPARE::BIGGER:  return ">";
        case COMPARE::EQUAL:   return "=";
    }
    return "?";
}

int main() {
    int a1[] = {1, 2, 3};
    int b1[] = {1, 2, 4};
    std::cout << "a={1,2,3} vs b={1,2,4}  -> " << toStr(Compare(a1, b1, 3, 3)) << "  期望 <\n";

    int a2[] = {1, 2, 5};
    int b2[] = {1, 2, 4};
    std::cout << "a={1,2,5} vs b={1,2,4}  -> " << toStr(Compare(a2, b2, 3, 3)) << "  期望 >\n";

    int a3[] = {1, 2, 3};
    int b3[] = {1, 2, 3};
    std::cout << "a={1,2,3} vs b={1,2,3}  -> " << toStr(Compare(a3, b3, 3, 3)) << "  期望 =\n";

    int a4[] = {1, 2};
    int b4[] = {1, 2, 3};
    std::cout << "a={1,2}   vs b={1,2,3}  -> " << toStr(Compare(a4, b4, 2, 3)) << "  期望 < (前缀更短)\n";

    int a5[] = {1, 2, 3};
    int b5[] = {1, 2};
    std::cout << "a={1,2,3} vs b={1,2}    -> " << toStr(Compare(a5, b5, 3, 2)) << "  期望 > (前缀更长)\n";

    int a6[] = {9};
    int b6[] = {1, 2, 3};
    std::cout << "a={9}     vs b={1,2,3}  -> " << toStr(Compare(a6, b6, 1, 3)) << "  期望 > (首位分出)\n";

    int a7[] = {1};
    int b7[] = {9, 0, 0};
    std::cout << "a={1}     vs b={9,0,0}  -> " << toStr(Compare(a7, b7, 1, 3)) << "  期望 < (首位分出)\n";

    return 0;
}