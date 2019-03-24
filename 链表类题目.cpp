/*
链表类通用方法以及题目分类


0、遍历链表
方法代码如下，head可以为空：

ListNode* p = head;
while(p!=NULL)
    p = p->next;
可以在这个代码上进行修改，比如要计算链表的长度：

ListNode* p = head;
int num = 0;
while(p!=NULL){
    num++;
    p = p->next;
}
如果要找到最后的节点，可以更改while循环中的条件，只不过需要加上head为NULL时的判断

if(!head) return head;
ListNode* p = head;
while(p->next!=NULL){
    p = p->next;
}
还可以使用两个指针，一个用来遍历，一个用来记录前一个

ListNode* p_before = NULL;
ListNode* p = head;
while(p!=NULL){
    p_before = p;
    p = p->next;
}
 

1、在head之前加上一个节点来简化计算
头结点的操作不同于中间节点，所以需要额外判断。穿插在很多题目中。

LeetCode 203 删除节点中的元素：https://leetcode.com/problems/remove-linked-list-elements/description/

2、两链表合并操作
l1代表链表1的头，l2代表链表2的头，通过以下方式来遍历链表（或是将while循环中的&&改成||）

while循环中如果是&&，则退出循环需要处理一个为空、一个还有的情况。如果while循环中为||，则在while循环体中需要判断其中一个为空的情况

还可以联合前一种方式，在head之前加上一个节点来简化计算

复制代码
while(l1!=NULL && l2!=NULL){
    if(l1 != NULL){
        //operator on l1
        l1 = l1->next;
    } 
    if(l2 != NULL){
        //operator on l2
        l2 = l2->next;
    }
}
//operator on the remain
复制代码
比如LeetCode2的两链表数相加的题：

复制代码
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(0);
    ListNode* current = result;
    int add = 0;
    while(l1!=NULL || l2!=NULL || add!=0){
        int num1 = 0;
        int num2 = 0;
        if(l1 != NULL){
            num1 = l1->val;
            l1 = l1->next;
        } 
        if(l2 != NULL){
            num2 = l2->val;
            l2 = l2->next;
        }
        ListNode* t = new ListNode((num1+num2+add)%10);
        add = (num1+num2+add)>=10?1:0;
        current->next = t;
        current = t;
    }
    return result->next;
}                            
复制代码
LeetCode2 两数相加：https://leetcode.com/problems/add-two-numbers/description/

LeetCode21 合并两链表：https://leetcode.com/problems/merge-two-sorted-lists/description/

LeetCode86 划分链表：https://leetcode.com/problems/partition-list/description/

LeetCode328 奇偶链表：https://leetcode.com/problems/odd-even-linked-list/description/

3、前后指针
l1在前，l2在后，让l2先走n步，当退出第二个循环时，l2位空，l1为倒数第n个节点。可以判断链表是否有环，确定环出现的位置等

复制代码
ListNode* l1 = head;
ListNode* l2 = head;
while(n-->0){
    l2 = l2->next;
}
while(l2 !=NULL){
    l1 = l1->next;
    l2 = l2->next;
}
复制代码
利用快慢指针可以找到链表的中间节点，l1每次向前走一格，l2每次向前走两个。

当l1、l2都从head开始时，while循环退出时，如果是链表节点数是奇数，则l1指向正中间，如果是偶数，则l1指向位置为中间后一个，例：如果有4个，则l1指向第3个

ListNode* l1 = head;
ListNode* l2 = head;
while (l2 != NULL && l2->next!= NULL) {
    l1 = l1->next;
    l2 = l2->next->next;
}  
当l1从head，l2从head->next开始，while循环退出时，如果是链表节点数是奇数，则l1指向正中间，如果是偶数，则l1指向位置为正中间，例：如果有4个，则l1指向第2个

ListNode* l1 = head;
ListNode* l2 = head->next;
while (l2 != NULL && l2->next!= NULL) {
　　l1 = l1->next;
　　l2 = l2->next->next;
}
LeetCode19 移除倒数第n个数：https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

LeetCode109 将链表转化为二叉树：https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

LeetCode141 判断链表是否有环：https://leetcode.com/problems/linked-list-cycle/description/

LeetCode142 找出链表有环的位置：https://leetcode.com/problems/linked-list-cycle-ii/description/

LeetCode160 找出两链表的交叉点：https://leetcode.com/problems/intersection-of-two-linked-lists/description/

287. Find the Duplicate Number https://leetcode.com/problems/find-the-duplicate-number/description/

数组的快慢指针

 View Code
1、数组也会形成环，同160的思路

4、利用前后指针处理链表内部数据，综合前几种处理方式
同样是l1和l2指针，一个在前一个在后，只是通过这样遍历一遍需要对链表中的数据进行修改。

思考方式：

1、假设进行中间某一点，看需要保存那些位置的值，即考虑n到n+1的情况

2、查看边界条件，开始位置的边界，结束位置的边界

反转链表的操作如下，注意将l1初始化为NULL，这样在反转之后可以让尾部节点为空

复制代码
ListNode* reverse(ListNode* head){
　　if(head == NULL || head->next == NULL) return head;
　　ListNode* l1 = NULL;
　　ListNode* l2 = head;
　　while(l2){
　　　　ListNode* t = l2->next;
　　　　l2->next = l1;
　　　　l1 = l2;
　　　　l2 = t;
　　}
　　return l1;
}
复制代码
 

 LeetCode24 反转链表中的元素：https://leetcode.com/problems/swap-nodes-in-pairs/description/

 LeetCode61 旋转链表：https://leetcode.com/problems/rotate-list/description/

LeetCode83 https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

LeetCode82 https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

LeetCode206 颠倒链表：https://leetcode.com/problems/reverse-linked-list/description/

1、取中间某一个位置，如果需要颠倒链表，需要保存两个值，一个是前面的指针，一个是当前指针，让当前指针的next指向前一个指针，然后两个指针整体向后移动一位，此时由于当前的next被修改了，所以next的位置需要提前被保存起来

2、考虑边界值，开始时前一个指针需要被设置为NULL，结束时，当前指针为NULL，前一个指针指向最后一个元素。

LeetCode143 重新整理链表 https://leetcode.com/problems/reorder-list/description/

是以上几种题型的综合，既有快慢指针，又有反转链表，还有合并链表

LeetCode234 回文链表 https://leetcode.com/problems/palindrome-linked-list/description/

LeetCode445 反向相加两数 https://leetcode.com/problems/add-two-numbers-ii/description/

 

5、链表排序
LeetCode 147 链表的插入排序：https://leetcode.com/problems/insertion-sort-list/description/

LeetCode 148 链表的归并排序：https://leetcode.com/problems/sort-list/description/

 

6、其他
LeetCode 237 删除节点：https://leetcode.com/problems/delete-node-in-a-linked-list/description/

LeetCode 430 铺展多级链表：https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
*/