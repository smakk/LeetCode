/*
Ugly Number II https://leetcode.com/problems/ugly-number-ii/description/

思路记住，维护3个pos，分别表示乘以3个质数后大于当前最大uglynumber的最小数，之后需要更新pos
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n<=0) return -1;
        vector<int> q(n);
        int t2(0),t3(0),t5(0);
        q[0]=1;
        for (int i=1;i<n;++i){
            q[i]=min(q[t2]*2,min(q[t3]*3,q[t5]*5));
            if (q[i]==q[t2]*2) ++t2;
            if (q[i]==q[t3]*3) ++t3;
            if (q[i]==q[t5]*5) ++t5;
        }
        return q[n-1];
    }
};
