/*
有另一种使用while循环和&&来做的方式

1、while循环中未加入add

2、add的再次计算以及新建ListNode的取值

3、加入头结点来简化不断增加链表的操作，不加时则需要额外判断第一个节点加入的情况
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
