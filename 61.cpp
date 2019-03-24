/*
总体思路还是前后指针，但k可能大于链表长度，所以前指针先走的步数不确定

解法一：前进k步，如果到达链表末尾时还未走k步，则说明k大于链表长度。需要重新从头走k%lenth步。然后前后指针同时向后走，到达末尾后反转。

1、如果k==0，也就是最后一步的链表断裂和重新连接的步骤的位置都是同一个，则会形成环，这里需要特别注意（head是绝对位置，before1和before2都是相对位置，当出现这类型赋值时一定要考虑边界条件）

2、head == NULL时，num为0，在除的时候num不能为0，所以开头需要除去head==NULL的情况

3、在判断k==0时候要注意位置，在对k取余数的时候也会出现余数为0的情况，所以也需要额外的判断k==0

4、k在循环的时候是不断递减的，需要先保存以下k的值。
*/

ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        int temp = k;
        ListNode t(0);
        t.next = head;
        ListNode* p1 = head;
        ListNode* before1 = &t;
        int num = 0;
        while(p1!=NULL && k-->0){
            num++;
            before1 = before1->next;
            p1 = p1->next;
        }
        if(p1 == NULL){
            k = temp%num;
            if(temp%num == 0) return head;
            p1 = head;
            before1 = &t;
            while(k-->0){
                before1 = before1->next;
                p1 = p1->next;
            }
        }
        
        ListNode* p2 = head;
        ListNode* before2 = &t;
        while(p1!=NULL){
            p1 = p1->next;
            p2 = p2->next;
            before1 = before1->next;
            before2 = before2->next;
        }
        before2->next = NULL;
        before1->next = head;
        return p2;
    }
	
/*
解法二：将链表变成循环链表。相比上一个方法，边界条件少了很多，代码也不容易写错，更加简洁

1、注意第一次while循环中的条件

2、求出链表长度之后，开始遍历的位置是尾部，以及遍历的长度是length-k。这点需要明确。
*/

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* p = head;
        int length = 1;
        while(p->next!=NULL){
            p = p->next;
            length++;
        }
        p->next = head;
        for(size_t i = 0;i<length-k%length;i++){
            p = p->next;
        }
        ListNode* result = p->next;
        p->next = NULL;
        return result;
    }
	
