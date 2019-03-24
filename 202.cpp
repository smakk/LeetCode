/*
Happy Number https://leetcode.com/problems/happy-number/description/

用hash来判断循环
*/

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
    s.insert(n);
    int next = 0;
    while (n != 1) {
        while (n>0) {
            int i = n % 10;
            n = n / 10;
            next = next + i*i;
        }
        if (s.find(next) != s.end())
            return false;
        else
            s.insert(next);
        n = next;
        next = 0;
    }
    return true;
    }
};

