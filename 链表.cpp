/*
最基础的方式要做到非常熟练，要熟练到不思考就能写，但又需明白各处的要求和陷阱
合并两个有序链表的操作，在前面加上一个初始节点，注意while循环和退出时的处理，理解如何处理其中一个链表遍历完的情况
*/
ListNode* merge(ListNode* l1, ListNode* l2) {
    //采用前面加一个空闲节点的方式来简化代码
    ListNode temp(-1);
    ListNode* result = &temp;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            result->next = l2;
            l2 = l2->next;
        }else {
            result->next = l1;
            l1 = l1->next;
        }
        result = result->next;
    }
    if (l1 == NULL)
        result->next = l2;
    else
        result->next = l1;
    return temp.next;
}

/*
快慢指针遍历链表,注意此时l1（慢指针）的位置，如果是链表节点数是奇数，则指向正中间，如果是偶数，则指向位置为中间后一个，例：如果有4个，则指向第3个
*/

ListNode* through(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* l1 = head;
    ListNode* l2 = head;
    while (l2 != NULL && l2->next!= NULL) {
        l1 = l1->next;
        l2 = l2->next->next;
    }  
        return l1;
}

/*
如果上述条件想让为4个时指向第2个，则修改初始情况为ListNode* l2 = head->next;
链表的归并排序
*/

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode temp(-1);
    ListNode* result = &temp;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            result->next = l2;
            l2 = l2->next;
        }else {
            result->next = l1;
            l1 = l1->next;
        }
        result = result->next;
    }
    if (l1 == NULL)
        result->next = l2;
    else
        result->next = l1;
    return temp.next;
}
ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* l1 = head;
    ListNode* l2 = head->next;
    while (l2 != NULL && l2->next!= NULL) {
        l1 = l1->next;
        l2 = l2->next->next;
    }
    //l1是中间节点
    l2 = l1->next;
    l1->next = NULL;

    return merge(sortList(head), sortList(l2));
}