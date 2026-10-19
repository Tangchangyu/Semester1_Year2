#include<iostream>

//先写一个头节点的链表；
template <class T>
struct Node {
    T data;
    Node* link; 
    Node(T val) : data(val), link(nullptr) {}
};

template <class T>
class List{
public: 
    Node<T>* head = nullptr;


};


//函数实现
template<class T>
bool findLastK(List<T> list, unsigned int k)//传入目标链表，参数k
{
    if (list.head == nullptr || k == 0){
        return 0;
    }

    int i = 0;  //计数器

    Node<T>* toolPointer = list.head;
    //用来遍历的指针

    Node<T>* target = nullptr;
    //初始化目标指针


    //1.跑到第k的时候开始驱动target
    //2.如果list长度小于k，则不会查找到，返回0
    while (toolPointer != nullptr){
        i++;
        toolPointer = toolPointer->link;
        if(i == k){
            target = list.head;
        }
        else if ( i > k ){
            target  = target->link;
        }

    }

    if (target == nullptr) return 0;    //链表不足k个元素，查找失败
    else{
        std::cout<<target->data;
        return 1;}

}