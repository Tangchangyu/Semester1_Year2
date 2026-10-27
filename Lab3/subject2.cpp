#include <iostream>

template<typename T>
struct Node
{
    Node *tail = nullptr;
    T data;
};

template<typename T>
class List
{
private:
    Node<T>* head = nullptr;

public:
    ~List() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* next = curr->tail;
            delete curr;
            curr = next;
        }
    }

    // 辅助函数：添加节点
    void push_back(T val) {
        Node<T>* newNode = new Node<T>{nullptr, val};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->tail != nullptr) {
            temp = temp->tail;
        }
        temp->tail = newNode;
    }

    // 辅助函数：打印链表
    void print() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->tail;
        }
        std::cout << "nullptr" << std::endl;
    }

    // 题目函数
    void reverse() {
        if (head == nullptr){
            return;
        }

        if (head->tail == nullptr){
            return;
        }

        Node<T>* prePointer = head;
        Node<T>* currPointer = head->tail;
        Node<T>* nextPointer = head->tail->tail;
        head->tail = nullptr;

        while (nextPointer != nullptr)
        {
            currPointer->tail = prePointer;
            prePointer = currPointer;
            currPointer = nextPointer;
            nextPointer = nextPointer->tail; // 修正：点操作符改为箭头
        }
        if (nextPointer == nullptr){
            currPointer->tail = prePointer;
            head = currPointer;
        }
    }
};

// 测试 main 函数
int main() {
    List<int> myList;

    // 1. 测试空链表反转
    std::cout << "初始空链表: ";
    myList.print();
    myList.reverse();
    std::cout << "反转空链表后: ";
    myList.print();

    // 2. 添加测试数据：1 -> 2 -> 3 -> 4 -> 5
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);

    std::cout << "\n原始链表: ";
    myList.print();

    // 3. 执行反转
    myList.reverse();

    std::cout << "反转后链表: ";
    myList.print(); 
    
    return 0;
}