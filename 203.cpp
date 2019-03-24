/*
LeetCode 203 删除节点中的元素
*/

ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL ) return NULL;
        ListNode* l = head;
        ListNode t(-1);
        t.next = head;
        ListNode* l_before = &t;
        while (l) {
            if (l->val == val)
                l_before->next = l->next;
            else
                l_before = l;
            l = l->next;
        }
        return t.next;
    }