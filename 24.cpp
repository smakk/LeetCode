/*
一、问题描述
　　给定一个链表，要求换他们的一对值，要求空间复杂度是常量，不能更改链表节点的值，只能更改指针。

　　例子：给定一个链表，如1->2->3->4，应该返回2->1->4->3。

二、问题解决
　　看到题目大概都能明白怎么去解，关键是如何转化成简单的代码描述。复习一定看一看代码，代码中，为了减去判断头节点是否空、整个链表是否为空使用了一种简单的描述方式，可以学习：

while ((a = *pp) && (b = a->next))
　　下面是整个代码，使用了指向指针的指针来解决这个问题。还可以方式第一次交换时第一个节点没有前结点的问题（这个问题还可以参考21题新建一个头节点的解决方案）

1、明白反转链表需要哪几个节点的值再思考

2、这里需要保存before，但是出现了头节点可能为空的情况
*/

ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode* list1 = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    ListNode* ii = swapPairs(list1);
    while (ii != NULL) {
        cout << ii->val << endl;
        ii = ii->next;
    }

    system("pause");
    return 0;
}

/*
下面是不使用指向指针的指针，而是新建一个头节点的解决方式（同样，在代码中判断下两个节点是否都存在，使用while条件的语句简化）：
*/
ListNode* swapPairs(ListNode* head) {
    ListNode f(-1);
    f.next = head;
    ListNode *p = &f;
    ListNode *a = head;
    ListNode *b;
    while (a && a->next) {
        b = a->next;
        a->next = b->next;
        b->next = a;
        p->next = b;
        p = a;
        a = p->next;
    }
    return f.next;
}