/*
LeetCode143 重新整理链表
*/

void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return ;
        ListNode* l1 = head;
        ListNode* l2 = head->next;
        while(l2 != NULL && l2->next!=NULL){
            l1 = l1->next;
            l2 = l2->next->next;
        }
        ListNode* head2 = l1->next;
        l1->next = NULL;
        l1 = NULL;
        while(head2 != NULL){
            ListNode* t = head2->next;
            head2->next = l1;
            l1 = head2;
            head2 = t;
        }
        //l1是反向链表的头
        ListNode t(0);
        ListNode* result = &t;
        while(l1 != NULL || head!=NULL){
            if(head!=NULL){
                result->next = head;
                head = head->next;
                result = result->next;
            }
            if(l1 != NULL){
                result->next = l1;
                l1 = l1->next;
                result = result->next;
            }
        }
        head = t.next;
        return ;
    }