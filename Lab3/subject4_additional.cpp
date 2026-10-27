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

    // 析构函数：简单清理无环链表内存
    ~List() {
        Node<T>* curr = head;
        int count = 0;
        while (curr != nullptr && count < 100) {
            Node<T>* next = curr->tail;
            delete curr;
            curr = next;
            count++;
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

    // 将尾部连到指定节点以构造成环
    void makeCircle(Node<T>* targetNode) {
        if (head == nullptr) return;
        Node<T>* temp = head;
        while (temp->tail != nullptr) {
            temp = temp->tail;
        }
        temp->tail = targetNode;
    }

    // 采用双指针快慢法寻找环的入口
    Node<T>* Funtion(){
        if (head == nullptr) return nullptr;
        Node<T>* fast = head;
        Node<T>* slow = head;
        if (head->tail == nullptr){
            return nullptr;
        }
        
        do
        {
            // 防御性检查：防止无环时访问空指针越界崩溃
            if (fast == nullptr || fast->tail == nullptr || fast->tail->tail == nullptr){
                return nullptr;
            }
            fast = fast->tail->tail;
            slow = slow->tail;
            
        } while (fast != slow); 

        // 出循环则说明有环，寻找环的入口
        fast = head;
        while (fast != slow)
        {
            fast = fast->tail;
            slow = slow->tail;
        }
        return fast;
    }
};

int main() {
    // ==========================================
    // 测试 1：无环链表
    // ==========================================
    std::cout << "=== 测试 1: 无环链表 ===" << std::endl;
    List<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);

    Node<int>* res1 = list1.Funtion();
    if (res1 == nullptr) {
        std::cout << "结果：链表无环 (符合预期)\n" << std::endl;
    } else {
        std::cout << "结果：发现环，入口值为 " << res1->data << std::endl;
    }

    // ==========================================
    // 测试 2：有环链表 (环从中间节点开始)
    // 链表结构: 1 -> 2 -> 3 -> 4 -> (指回 2)
    // ==========================================
    std::cout << "=== 测试 2: 有环链表 (环入口为 2) ===" << std::endl;
    List<int> list2;
    list2.push_back(1);
    list2.push_back(2); // 环的入口
    list2.push_back(3);
    list2.push_back(4);

    // 获取节点 2 的指针
    Node<int>* h2 = list2.getHead();
    Node<int>* node2 = h2->tail; // 指向值为 2 的节点

    // 让尾部 4 指向 2，形成环
    list2.makeCircle(node2);

    Node<int>* res2 = list2.Funtion();
    if (res2 != nullptr) {
        std::cout << "结果：发现环！环的入口节点值为: " << res2->data << " (符合预期)" << std::endl;
    } else {
        std::cout << "结果：链表无环" << std::endl;
    }

    return 0;
}