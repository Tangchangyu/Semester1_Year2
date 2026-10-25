//破题点在于——链表相交后，便不会再次分叉，成为一个y字型
//利用双指针遍历，直到二者相交

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
    Node<T>* findIntersection(List list1,List list2){
        Node<T> pointer1 = list1.head;
        Node<T> pointer2 = list2.head;

        bool endTheLoop = false;

        while (endTheLoop == false&&pointer1== nullptr)
        {
            pointer1 = ((pointer1 != nullptr)?pointer1->tail:list2.head);
            pointer2 = ((pointer2 != nullptr)?pointer2->tail:list2.head);
            if (p1 == nullptr){
                endTheLoop = true;
            }
            if (pointer1==pointer2){
                return pointer1;
            }
        }
        
    }

    return nullptr;
};
