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
    List() : head(nullptr) {}

    ~List() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* next = curr->tail;
            delete curr;
            curr = next;
        }
    }

    // 尾插法添加节点
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

    // 获取头节点
    Node<T>* getHead() const {
        return head;
    }

    // 设置头节点
    void setHead(Node<T>* h) {
        head = h;
    }

    // 查找相交节点函数
    static Node<T>* findIntersection(const List& list1, const List& list2){
        Node<T>* pointer1 = list1.head; 
        Node<T>* pointer2 = list2.head; 

        while (pointer1 != pointer2)
        {
            pointer1 = (pointer1 != nullptr) ? pointer1->tail : list2.head;
            pointer2 = (pointer2 != nullptr) ? pointer2->tail : list1.head;
        }
        return pointer1; // 返回相交节点或 nullptr
    }
};

int main() {
    // 构造一个 Y 型相交链表
    // 公共部分（交点及之后）：30 -> 40 -> 50
    Node<int>* commonNode = new Node<int>{nullptr, 30};
    commonNode->tail = new Node<int>{nullptr, 40};
    commonNode->tail->tail = new Node<int>{nullptr, 50};

    // 链表 1：1 -> 2 -> (30 -> 40 -> 50)
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    // 将公共部分接在 list1 的末尾
    Node<int>* temp1 = list1.getHead();
    while (temp1->tail != nullptr) {
        temp1 = temp1->tail;
    }
    temp1->tail = commonNode;

    // 链表 2：9 -> (30 -> 40 -> 50) 
    List<int> list2;
    list2.push_back(9);
    // 将公共部分接在 list2 的末尾
    Node<int>* temp2 = list2.getHead();
    while (temp2->tail != nullptr) {
        temp2 = temp2->tail;
    }
    temp2->tail = commonNode;

    // 测试查找相交节点
    Node<int>* intersection = List<int>::findIntersection(list1, list2);

    if (intersection != nullptr) {
        std::cout << "找到相交节点，其值为: " << intersection->data << std::endl; // 预期输出 30
    } else {
        std::cout << "两链表不相交" << std::endl;
    }

    // 注意：由于 list1 和 list2 共享了 commonNode 及其后面的内存，
    // 在析构时为了避免重复释放，我们可以把其中一个链表的连接断开，
    temp2->tail = nullptr; 

    return 0;
}