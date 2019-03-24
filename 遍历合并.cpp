/*
今天做了leetcode67题，两个2进制数相加，回想了一下其实有很多这种类型的题，比如leetcode2两数相加。

在做这种题时我自己的思路就是先循环遍历一个短的，然后跳出循环，判断是哪个结束，再接着合并。比如67题如下：

给定两个二进制的字符串，比如a=”11“，b=”1“，返回结果”100“。
*/

string addBinary(string a, string b) {
    int pos_a = a.size() -1;
    int pos_b = b.size() -1;
    int length = max(a.size(), b.size())+1;
    string result(length,' ');
    int add = 0;
    int i = length - 1;
    //从后向前遍历，直到一个string用完
    for ( ; i >= 0; i--) {
        if (-1 == pos_a || -1 == pos_b)
            break;
        //有进位的情况
        if (a[pos_a] + b[pos_b] + add - '0' - '0'>= 2) {
            result[i] = (a[pos_a] -'0' + b[pos_b] - '0'+ add)%2 + '0';
            add = 1;
        }else{
            result[i] = (a[pos_a] - '0' + b[pos_b] - '0' + add) + '0';
            add = 0;
        }
        pos_a--;
        pos_b--;
    }
    //如果两个都用完
    if (-1 == pos_a && -1 == pos_b) {
        if (add == 0)
            result.erase(0, 1);
        else
            result[0] = '1';
        return result;
    }
    //如果只有a用完
    if (-1 == pos_a) {
        while (pos_b != -1) {
            result[i--] = (b[pos_b] -'0'+ add)%2 + '0';
            add = (b[pos_b--] + add - '0')/2 ;
        }
        if (add == 1)
            result[0] = '1';
        else
            result.erase(0,1);
    }else{
    //如果只有b用完
        while (pos_a != -1) {
            result[i--] = (a[pos_a]-'0' + add) % 2+'0';
            add = (a[pos_a--] + add - '0') / 2 ;
        }
        if (add == 1)
            result[0] = '1';
        else
            result.erase(0, 1);
    }
    return result;
}


/*
这使得代码再跳出第一次循环后还需要做很多的工作，而且一不小心还会因为边界条件出错，所以需要寻找一个更加简洁的方法来处理这种问题，寻找leetcode中这种题，多练习一下。
*/

string addBinary(string a, string b) {
    string result = "";
    int pos_a = a.size() - 1;
    int pos_b = b.size() - 1;
    int add = 0;
    while (pos_a != -1 || pos_b != -1 || add == 1) {
        if (pos_a != -1)
            add += a[pos_a--] - '0';
        if (pos_b != -1)
            add += b[pos_b--] - '0';
        result = char(add % 2 + '0') + result;
        add = add/2;
    }
    return result;
}

/*
上面这种方式代码要简洁很多而且也不容易写错，注意char和string可以直接进行拼接。
在考虑leetcode2，两数相加问题。
同样是使用和上述一样的方法
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int add = 0;
    ListNode result(-1);
    ListNode* pos = &result;
    while (l1 != NULL || l2 != NULL || add != 0) {
        if (l1 != NULL) { add += l1->val; l1 = l1->next; }
        if (l2 != NULL) { add += l2->val; l2 = l2->next; }
        ListNode *temp = new ListNode(add % 10);
        pos->next = temp;
        pos = pos->next;
        add = add / 10;
    }
    return result.next;
}
