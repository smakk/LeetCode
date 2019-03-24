/*
LeetCode109：将链表转化为二叉树

需要注意的是在将链表断成3个部分的时候前一部分有额外情况，那就是链表只有两个节点的时候，l1指向第一个节点，前一部分应该为NULL
*/

TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL){
            TreeNode* result = new TreeNode(head->val);
            return result;
        }
        ListNode* before_l1 = NULL;
        ListNode* l1 = head;
        ListNode* l2 = head->next;
        while(l2!=NULL && l2->next!=NULL){
            before_l1 = l1;
            l1 = l1->next;
            l2 = l2->next->next;
        }
        TreeNode* node = new TreeNode(l1->val);
        if(before_l1 == NULL){
            node->left = sortedListToBST(NULL);
        }else{
            before_l1->next = NULL;
            node->left = sortedListToBST(head);
        }
        node->right = sortedListToBST(l1->next);
        return node;
    }