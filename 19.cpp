/*
一、问题描述
　　给定一个链表和一个数n，要求删除该链表的倒数第n个节点。给定n一定是合理的，只遍历一遍

　　例子：给定链表1->2->3->4->5，n=2，执行删除操作之后链表变成1->2->3->5。

二、问题解决
　　这种遍历一遍找出第几个、倒数第几个、中间节点的题，都是通过两个节点来解决，本题中，先让first节点走n步，再让second和first节点同时向后走，知道first为空。（想吐槽这种方式，一个节点遍历两次和两个节点遍历一次不是一样的么？难道就不算是遍历两次）

　　要实现遍历一次，只能遍历的时候把各节点地址存起来了。空间复杂度变成n。我不管，这才是真正的遍历一遍。

当链表长度为n时会出现删除头节点的情况，加上一个头节点可以简化这种操作
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//19
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) return NULL;
    vector<ListNode*> v;
    ListNode* first = head;
    while (first != NULL) {
        v.emplace_back(first);
        first = first->next;
    }
    if (n == 1&& v.size()==1)
        return NULL;
    if (v.size() == n) return head->next;
    first = v.at(v.size()-n-1);
    first->next = first->next->next;
    return head;
}

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    ListNode* result = removeNthFromEnd(&node1,2);
    while (result != NULL) {
        cout << result->val << endl;
        result = result->next;
    }

    system("pause");
    return 0;
}