/*
LeetCode328 奇偶链表
*/

ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* head1 = head,*current1 = head;
        ListNode* head2 = head->next,*current2 = head->next;
        ListNode* current = head->next->next;
        while(current != NULL){
            current1->next = current;
            current1 = current1->next;
            current = current->next;
            if(current != NULL){
                current2->next = current;
                current2 = current2->next;
                current = current->next;
            }
        }
        current1->next = head2;
        current2->next = NULL;
        return head1;
    }