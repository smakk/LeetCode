/*
LeetCode 237 删除节点
*/

void deleteNode(ListNode* node) {
        if (!node || !node->next)
            return;
        node->val = node->next->val;
        node->next = node->next->next;
    }