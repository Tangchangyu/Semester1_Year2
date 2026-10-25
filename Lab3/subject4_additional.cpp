//判断是否成环——地址相等

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

    //采用双指针快慢法
    Node<T>* Funtion(){
        Node<T>* fast = head;
        Node<T>* slow = head;
        if (head->tail == nullptr){
            return nullptr;
        }
        do
        {
            if (fast == nullptr){
                break;
            }
            fast = fast->tail->tail;
            slow = slow->tail;
            
        } while (fast != head);


        //出循环则说明有环
        fast = head;
        while (fast != slow)
        {
            fast = fast->tail;
            slow = slow->tail;
        }
        return slow;
        
        
    }
};