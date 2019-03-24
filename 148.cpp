/*
LeetCode 148 链表的归并排序
*/
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode temp(-1);
    ListNode* result = &temp;
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
    else
        result->next = l1;
    return temp.next;
}
ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* l1 = head;
    ListNode* l2 = head->next;
    while (l2 != NULL && l2->next!= NULL) {
        l1 = l1->next;
        l2 = l2->next->next;
    }
    //l1是中间节点
    l2 = l1->next;
    l1->next = NULL;

    return merge(sortList(head), sortList(l2));
}