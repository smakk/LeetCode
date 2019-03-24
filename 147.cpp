/*
LeetCode 147 链表的插入排序
*/


ListNode* insertionSortList(ListNode* head) {
    ListNode t(INT_MIN);
    t.next = NULL;
    ListNode* l1 = head;
    while (l1 != NULL) {
        //删除l1节点
        ListNode* next = l1->next;
        //从头寻找插入点
        ListNode* before_current = &t;
        ListNode* current = t.next;
        while (current != NULL && current->val<l1->val) {
            before_current = before_current->next;
            current = current->next;
        }
        l1->next = current;
        before_current->next = l1;


        l1 = next;
    }
    return t.next;
}