/*
完成整个大的目标需要两个条件

1、翻转m到n的链表

2、将before_m的next指向n，m的next指向later_n

然后遍历，在遍历过程中对几个过程进行处理，小于m时，等于m时，大于m小于等于n时
*/

		ListNode t(0);
        t.next = head;
        ListNode* before_m;
        ListNode* _m;
        ListNode* _n;
        ListNode* later_n;
        ListNode* current = head;
        ListNode* before = &t;
        int num = 0;
        while(current){
            num++;
            if(num<m){
                before = current;
                current = current->next;
            }else if(num == m){
                before_m = before;
                _m = current;
                ListNode* t = current->next;
                current->next = NULL;
                before = current;
                current = t;
            }else if(num <= n){
                ListNode* t = current->next;
                current->next = before;
                before = current;
                current = t;
            }else{
                break;
            }
        }
        _n = before;
        later_n = current;
        
        before_m->next = _n;
        _m->next = later_n;
        return t.next;

