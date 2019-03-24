/*
Best Time to Buy and Sell Stock https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

1、思路是遍历每一个位置的时候和前面的最小值相减

2、注意size等于0是为什么会错误
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int low = INT_MAX;
        int max = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<low)
                low = prices[i];
            if(prices[i]-low > max)
                max = prices[i]-low;
        }
        return max;
    }
};
