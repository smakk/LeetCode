/*
LeetCode160 找出两链表的交叉点
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        ListNode* l = headA;
        while(l!=NULL){
            lengthA++;
            l = l->next;
        }
        int lengthB = 0;
        l = headB;
        while(l!=NULL){
            lengthB++;
            l = l->next;
        }
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        if(lengthA<lengthB){
            int t = lengthB-lengthA;
            for(size_t i =0;i<t;i++)
                l2 = l2->next;
        }else{
            int t = lengthA-lengthB;
            for(size_t i =0;i<t;i++)
                l1 = l1->next;
        }
        while(l1 != l2){
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1;
    }
