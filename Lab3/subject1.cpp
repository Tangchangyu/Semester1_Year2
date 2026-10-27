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

int main() {
    // 创建一个整型链表实例
    List<int> myList;

    // 手动构建链表: 10 -> 20 -> 30 -> 40 -> 50
    myList.head = new Node<int>(10);
    myList.head->link = new Node<int>(20);
    myList.head->link->link = new Node<int>(30);
    myList.head->link->link->link = new Node<int>(40);
    myList.head->link->link->link->link = new Node<int>(50);

    // 测试 1：查找倒数第 2 个元素（预期输出 40）
    std::cout << "测试 1 (倒数第 2 个): ";
    if (!findLastK(myList, 2)) {
        std::cout << "查找失败";
    }
    std::cout << std::endl;

    // 测试 2：查找倒数第 5 个元素，即头节点（预期输出 10）
    std::cout << "测试 2 (倒数第 5 个): ";
    if (!findLastK(myList, 5)) {
        std::cout << "查找失败";
    }
    std::cout << std::endl;

    // 测试 3：查找倒数第 6 个元素（超出链表长度，预期失败）
    std::cout << "测试 3 (倒数第 6 个 - 超长): ";
    if (!findLastK(myList, 6)) {
        std::cout << "查找失败 (符合预期)";
    }
    std::cout << std::endl;

    // 测试 4：k = 0 的边界情况（预期失败）
    std::cout << "测试 4 (k = 0): ";
    if (!findLastK(myList, 0)) {
        std::cout << "查找失败 (符合预期)";
    }
    std::cout << std::endl;

    // 清理动态分配的内存（养成良好习惯，防止内存泄漏）
    Node<int>* curr = myList.head;
    while (curr != nullptr) {
        Node<int>* nextNode = curr->link;
        delete curr;
        curr = nextNode;
    }
    myList.head = nullptr;

    return 0;
}