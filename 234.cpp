/*
LeetCode234 回文链表

注意就情况的区分
*/

bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* l1 = head;
        ListNode* l2 = head->next;
        while(l2!=NULL && l2->next!=NULL){
            l1 = l1->next;
            l2 = l2->next->next;
        }
        l2 = l1->next;
        l1->next = NULL;
        l1 = NULL;
        while(l2 != NULL){
            ListNode* t = l2->next;
            l2->next = l1;
            l1 = l2;
            l2 = t;
        }
        //l1是后一部分的头
        while(l1!=NULL && head!=NULL){
            if(l1->val != head->val) return false;
            l1 = l1->next;
            head = head->next;
        }
        return true;
    }

