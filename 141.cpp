/*
LeetCode141 判断链表是否有环：

判断l1等于l2的位置不能写错
*/

bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode t(0);
        t.next = head;
        ListNode* l1 = &t;
        ListNode* l2 = &t;
        while(l2!=NULL && l2->next!=NULL){
            l1 = l1->next;
            l2 = l2->next->next;
            if(l1 == l2) return true;
        }
        return false;
    }