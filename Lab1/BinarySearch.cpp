#include<iostream>

int FindNumber(int num[], int size , int t){
    int *left = num;
    int *right = num +size - 1;
   
    while (left <= right){

    int *mid = left + (right - left)/2;
        //在迭代left/right的时候，跳过mid
        if (t < *mid ){
            right = mid - 1;
        }

        else if (t > *mid){
            left = mid + 1;
        }

        else if (t == *mid){
            return (mid - num);
        }
    }

    return (left - num);

 }
int main() {
    int a[] = {1, 3, 5, 7, 9};

    std::cout << "命中中间  t=5  -> " << FindNumber(a, 5, 5)  << "  (期望 2)\n";
    std::cout << "命中开头  t=1  -> " << FindNumber(a, 5, 1)  << "  (期望 0)\n";
    std::cout << "命中结尾  t=9  -> " << FindNumber(a, 5, 9)  << "  (期望 4)\n";
    std::cout << "插入最前  t=0  -> " << FindNumber(a, 5, 0)  << "  (期望 0)\n";
    std::cout << "插入最后  t=10 -> " << FindNumber(a, 5, 10) << "  (期望 5)\n";
    std::cout << "插入中间  t=4  -> " << FindNumber(a, 5, 4)  << "  (期望 2)\n";

    return 0;
}