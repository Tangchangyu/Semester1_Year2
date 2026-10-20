#include<iostream>

//基本思路——做备份，然后交换值

void reverseNums(int *array,int size){
    int temp = 0;
    if (size != 0)
    {    for (int i = 0; i < size/2; i ++){
            temp = array[i];
            array[ i]= array[size - i - 1];
            array[size - i - 1]=temp;
        }
    }
}

int main() {
    using namespace std;

    // 1. 定义测试数组
    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    // 2. 打印反转前的数组
    cout << "反转前: ";
    for (int i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // 3. 调用原地反转函数
    reverseNums(nums, size);

    // 4. 打印反转后的数组
    cout << "反转后: ";
    for (int i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}