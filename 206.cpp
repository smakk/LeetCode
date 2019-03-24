/*
LeetCode206：颠倒链表
*/

ListNode* reverseList(ListNode* head) {
        ListNode* before = NULL;
        while(head){
            ListNode* t = head->next;
            head->next = before;
            before = head;
            head = t;
        }
        return before;
    }