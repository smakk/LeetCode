/*
LeetCode142 找出链表有环的位置

本题链表可能没有环
*/

ListNode *detectCycle(ListNode *head) {
        if(!head) return  NULL;
        ListNode t(0);
        t.next = head;
        ListNode* l1 = head;
        ListNode* l2 = head;
        while(l2!=NULL && l2->next!=NULL){
            l1 = l1->next;
            l2 = l2->next->next;
            if(l1 == l2) break;
        }
        if(l2 == NULL || l2->next == NULL) return NULL;
        ListNode* l3 = head;
        while(l1 != l3){
            l1 = l1->next;
            l3 = l3->next;
        }
        return l1;
    }