/*
LeetCode 430 铺展多级链表

这题和链表相关不大，会递归或是迭代的写法都可以。
*/

Node* flatten(Node* head) {
        if(head == NULL || (head->child == NULL && head->next == NULL)) return head;
        if(head->child == NULL ) {
            head->next = flatten(head->next);
            head->next->prev = head;
            return head;
        }else if(head->next == NULL){
            head->next = flatten(head->child);
            head->next->prev = head;
            head->child = NULL;
            return head;
        }else{
            Node* n = flatten(head->next);
            Node* c = flatten(head->child);
            head->next = c;
            c->prev = head;
            Node* t = head;
            while(c->next!=NULL){
                c = c->next;
            }
            c->next = n;
            n->prev = c;
            head->child = NULL;
            return head;
        }
    }

