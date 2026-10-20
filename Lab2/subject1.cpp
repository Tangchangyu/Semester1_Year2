#include<iostream>
//给定一个字符串，统计每个字符出现的次数。

//用数组下标对应acsii码

//具体方法


unsigned int* function(const char* word,int length){

    unsigned int* nums= new unsigned int[256]();//防止野指针

    for (int i = 0 ; i < length ; i++){
        nums[(unsigned char)word[i]]++;
    }
    return nums;
}

int main() {


    const char* text = "hello world";//测试字符串
    int length = strlen(text);

    unsigned int* result = function(text, length);

    // 打印结果
    std::cout << "字符串 \"" << text << "\" 中各字符出现的次数为：" << std::endl;
    for (int i = 0; i < 256; i++) {
        if (result[i] > 0) {
            std::cout << "字符 '" << (char)i << "' : " << result[i] << " 次" << std::endl;
        }
    }

    delete[] result;

    return 0;
}