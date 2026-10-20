#include<random>
#include<cmath>
#include<iostream>
#include <string>
using std::string;
using std::pow;

//由于多项式为稠密多项式，采用单数组存储系数，下标对应指数次数
//迭代法实现f1
double F1a(unsigned int n, const double* a, double x) {
    double result = 0.0;
    for (unsigned int i = 0; i <= n; ++i) {
        result += a[i] * std::pow(x, i); // 计算 a[i] * x^i
    }
    return result;
}

//递归实现f1
// 递归辅助函数
double F1b_helper(unsigned int n, const double* a, double x, unsigned int index) {
    if (index > n) {
        return 0.0;
    }
    // 当前项 a[index] * x^index + 剩余项的递归和
    return a[index] * std::pow(x, index) + F1b_helper(n, a, x, index + 1);
}

double F1b(unsigned int n, const double* a, double x) {
    return F1b_helper(n, a, x, 0); // 从第 0 项（a0 * x^0）开始递归
}



//F2
double F2a(unsigned int n, const double* a, double x){
    double result = 0;
    for (int i = n;i> 0 ;i --){
        result = result*x + a[i];
    }
    result += a[0];
    return result;
}

//递归法
double F2bhelper(unsigned int n, const double* a, double x, unsigned int index){
    if (index == n){
        return a[n];
    }

    else {
        return (a[index]+x*(F2bhelper(n,a,x,index+1)));
    }

}
double F2b(unsigned int n, const double* a, double x){
    return F2bhelper(n,a,x,0);
}


//f3实现
double F3(int n , double x){
    double result = 0.0;
    for(double i = 1.0; i <=n; i++){
        result += pow(x,i)/i;
    }
    result++;
    return result;
}
