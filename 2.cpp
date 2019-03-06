/*
    there is another way, in the while loop can use &&

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode l(0);
        ListNode *result = &l;
        ListNode *index = result;
        int add = 0;
        while(l1 != NULL || l2 != NULL || add !=0){
            int t = 0;
            if(l1 != NULL){
                t = t+l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                t = t+l2->val;
                l2 = l2->next;
            }
            if(add != 0){
                t = t+1;
                add = 0;
            }
            add = t/10;
            index->next = new ListNode(t%10);
            index = index->next;
        }
        return result->next;
    }
};
