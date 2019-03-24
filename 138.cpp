/*
LeetCode138：复制随机链表的指针
*/

RandomListNode* copyRandomList(RandomListNode *head, map<int, RandomListNode*>& m) {
    if (head == NULL) return NULL;
    if (m.find(head->label) == m.end()) {
        RandomListNode* t = new RandomListNode(head->label);
        m.insert(pair<int, RandomListNode*>(head->label, t));
        t->next = copyRandomList(head->next, m);
        t->random = copyRandomList(head->random, m);
        return t;
    }
    else {
        return (*m.find(head->label)).second;
    }
}
RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) return NULL;
    map<int,RandomListNode*> m;
    return copyRandomList(head,m);
}