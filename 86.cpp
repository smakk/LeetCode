/*
LeetCode86：分割链表

注意退出while循环后将两个分别的链表拼起来的时候，大于val的链表尾部要设为空。
*/

ListNode* partition(ListNode* head, int x) {
        ListNode t1(0);
        ListNode t2(0);
        ListNode* less = &t1;
        ListNode* bigger = &t2;
        ListNode* current = head;
        while(current!=NULL){
            if(current->val < x){
                less->next = current;
                less = less->next;
            }else{
                bigger->next = current;
                bigger = bigger->next;
            }
            current = current->next;
        }
        bigger->next = NULL;
        less->next = t2.next;
        return t1.next;
    }