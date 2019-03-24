/*
一、问题描述
　　给定两个链表，将他们合并成一个，其中节点值要按顺序排列。

　　例子：给定链表1为1->2->4，链表2为1->3->4。合并之后链表为1->1->2->3->4->4

二、问题解决
　　思路一：

　　每次比较两个头结点的值，看谁的小，依次将他们都串起来

　　代码中用到一个巧妙的办法，先初始化了一个为-1的节点，然后返回该节点的next（不然一个空指针没有办法执行next，这样在进入循环的时候要判断l1和l2第一个节点的大小）。可以使代码繁琐程度大大减少。

while循环中入股哦是&&，则退出循环需要处理一个为空、一个还有的情况。如果while循环中为||，则在while循环体中需要判断其中一个为空的情况
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    ListNode r(-1);
    ListNode* result = &r;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            result->next = l2;
            l2 = l2->next;
        }else {
            result->next = l1;
            l1 = l1->next;
        }
        result = result->next;
    }
    if (l1 == NULL)
        result->next = l2;
    if (l2 == NULL)
        result->next = l1;
    return r.next;
}

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(4);
    ListNode* list1 = &node1;
    node1.next = &node2;
    node2.next = &node3;

    ListNode node4(1);
    ListNode node5(3);
    ListNode node6(4);
    ListNode* list2 = &node4;
    node4.next = &node5;
    node5.next = &node6;

    ListNode* ii = mergeTwoLists(list1, list2);
    while (ii != NULL) {
        cout << ii->val << endl;
        ii = ii->next;
    }

    system("pause");
    return 0;
}