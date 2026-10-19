//寻找带头节点的两个链表（字符）的共同后缀的起始位置；


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

template<typename T>
unsigned short findLength(List<T> list){
    int i = 0;  //计数器
    Node<T> *pointer = list.head;
    while(pointer != nullptr){
        i++;
        pointer = pointer->link;
    }
    return i;
}//返回链表的长度

template <class T>
void findPostfix(Node<T>*& no1,Node<T>*& no2,List<T> list1,List<T> list2){
    unsigned short L1 = findLength(list1);
    unsigned short L2 = findLength(list2);

    Node<T>* BigPointer= (L1>=L2? list1.head:list2.head);
    Node<T>* SmallPointer= (L1>=L2? list2.head:list1.head);

    unsigned short detaL= (L1>=L2? (L1-L2):(L2-L1));
    
    for (int i = 0; i < detaL ; i++){
        BigPointer = BigPointer->link;
    }//尾端对齐


    bool flag = false;  // 用于判定是否从某一个字母开始，两单词都是相等
    while ( BigPointer != nullptr){
        if (BigPointer->data != SmallPointer->data){
            if (flag == true){
                no1 = nullptr;
                no2 = nullptr;
            }//出现相同字母后又出现不同部分——重置
            flag = false;
        }
        
        else if (BigPointer->data == SmallPointer->data && flag == false){
            no1 = BigPointer;
            no2 = SmallPointer;
            flag = true;
        }//出现相同字母

        else if (BigPointer->data == SmallPointer->data && flag != false)  {


        }  //后续字母依旧相同：不做操作
    
        BigPointer = BigPointer->link;
        SmallPointer = SmallPointer->link;
    }
}//nullptr——不存在相同后缀