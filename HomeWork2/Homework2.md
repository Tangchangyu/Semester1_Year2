### 题目1：

已知一个带有表头结点的单链表，结点结构为(data, link)。假设该链表只给出了头指针list。在不改变链表的前提下，设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点。若查找成功，则输出该结点的data域的值，并返回1，否则，只返回0。

#### 解题思路：

对链表进行遍历，指针记为（`pointe1`），遍历到第k个元素时，用另一个指针（`pointer2`）指向第1个元素，并跟随循环一起遍历。这样`pointer1`遍历结束时，`pointer2`指向的就是倒数第k个元素；

注意当链表长度小于k时，查找失败，返回0；

#### 伪代码：

```cpp
算法：findLastK(list, k)
输入：带头结点的链表 list，无符号整数 k
输出：查找成功返回 1（并输出结点值），失败返回 0

1. i = 0                      // 计数器
2. toolPointer = list.head    // 用来遍历的指针
3. target = 为空              // 初始化目标指针

4. while toolPointer != 为空 do
5.     i = i + 1
6.     toolPointer = toolPointer->link
7.     if i == k then
8.         target = list.head // 跑到第 k 个位置时开始驱动 target
9.     else if i > k then
10.        target = target->link
11.    end if
12. end while

13. if target == 为空 then
14.    return 0               // 链表不足 k 个元素，查找失败
15. else
16.    输出 target->data       // 查找成功，输出结点的值
17.    return 1
18. end if
```

#### 分析：

- 算法只对数组进行一次遍历，时间复杂度为$O(n)$，其中n为数组长度；

---

### 题目2：

假定采用带头结点的单链表保存单词，当两个单词有相同后缀时，可共享相同的后缀存储空间。设str1和str2分别指向两个单词所在单链表的头结点，链表结点结构为(data,next)。设计一个时间上尽可能高效的算法，找出由str1和str2所指向两个链表共同后缀的起始位置，并给出所设计算法的时间复杂度。

#### 解题思路：

要找到两个链表的共同后缀，首先要对两个链表做**尾端对齐**，具体实现方法是，对较长的链表，先用指针指向第$\Delta L$个位置。

此后，对两个链表进行遍历和比较，即可寻找到共同后缀；

#### 伪代码

```cpp
辅助函数FindLength,返回链表长度

1. L1 = findLength(list1)
2. L2 = findLength(list2)

3. // 通过长度关系初始化大长链表指针和小长链表指针
   BigPointer = (L1 >= L2 ? list1.head : list2.head)
   SmallPointer = (L1 >= L2 ? list2.head : list1.head)
   detaL = (L1 >= L2 ? (L1 - L2) : (L2 - L1))

4. // 尾端对齐
   for i = 0 到 detaL - 1 do
       BigPointer = BigPointer->link
   end for

5. flag = false               // 判定标志位：是否从某字母开始两单词相同
6. while BigPointer != 为空 do
7.     if BigPointer->data != SmallPointer->data then
8.         if flag == true then
9.             no1 = 为空
10.            no2 = 为空
11.        end if
12.        flag = false       // 出现不同字母，重置标志
13.    else if BigPointer->data == SmallPointer->data 且 flag == false then
14.        no1 = BigPointer   // 首次出现相同字母，记录起始地址
15.        no2 = SmallPointer
16.        flag = true
17.    else if BigPointer->data == SmallPointer->data 且 flag == true then
18.        // 后续字母依旧相同：不做操作，保持 flag 为 true
19.    end if

20.    BigPointer = BigPointer->link
21.    SmallPointer = SmallPointer->link
22. end while
```

#### 分析

- 由于要先对两链表进行遍历，时间复杂度为$O(n_1+n_2)$

- 寻找共同后缀的过程，总循环次数为$|n_1-n_2|$

- 综上，总时间复杂度为$O(n_1+n_2)$





#### 注意

若是两个字符数组共享后缀的内存空间，则只需判断两个指针地址是否相等，而无需对后续节点进行判断