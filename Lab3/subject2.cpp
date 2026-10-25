

template<typename T>
struct Node
{
    Node *tail=nullptr;
    T data;
};


template< typename T>
class List
{
private:
    Node<T>* head=nullptr;

public:
    //基本想法：调转指针方向，并把头节点指针指向最后一个指针
    void reverse(){
        if (head == nullptr){
            return ;
        }

        if (head->tail== nullptr){
            return;
        }

        Node<T>* head_backup = head;
        Node<T>* prePointer = head;//用于遍历和反转指针的中间容器
        Node<T>* currPointer = head->tail;
        Node<T>* nextPointer = head->tail->tail;
        head->tail = nullptr;

        while (nextPointer != nullptr)
        {
            currPointer->tail= prePointer;
            prePointer= currPointer;
            currPointer = nextPointer;
            nextPointer = nextPointer.tail;
        }
        if (nextPointer == nullptr){
            currPointer->tail = prePointer;
            head = currPointer;
        }

        
    }
    
};

