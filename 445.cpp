/*
LeetCode445 反向相加两数
*/


ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* l1 = NULL;
        ListNode* l2 = head;
        while(l2){
            ListNode* t = l2->next;
            l2->next = l1;
            l1 = l2;
            l2 = t;
        }
        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new1 = reverse(l1);
        ListNode* new2 = reverse(l2);
        //加两个链表，前面有一个题和这里一模一样
        int add = 0;
        ListNode* current1 = new1;
        ListNode* current2 = new2;
        ListNode result(0);
        ListNode* current = &result;
        while(current1 || current2 || add==1){
            int num1 = 0;
            int num2 = 0;
            if(current1){
                num1 = current1->val;
                current1 = current1->next;
            } 
            if(current2) {
                num2 = current2->val;
                current2 = current2->next;
            }
            current->next = new ListNode((num1+num2+add)%10);
            add = (num1+num2+add)/10;
            current = current->next;
        }
        
        return reverse(result.next);
    }