/*
LeetCode82：消除重复元素2
*/

ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        ListNode t(0);
        t.next = head;
        ListNode* before = &t;
        while(p!=NULL){
            int num = p->val;
            p = p->next;
            bool change = false;
            while(p!=NULL && p->val == num){
                change = true;
                p = p->next;
            }
            if(change){
                before->next = p;
            }else{
                before = before->next;
            }
        }
        return t.next;
    }
