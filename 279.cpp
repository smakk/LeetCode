/*
Perfect Squares https://leetcode.com/problems/perfect-squares/description/

两种动态规划的思路
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(1, 0);
        while (dp.size() <= n) {
            int m = dp.size(), val = INT_MAX;
            for (int i = 1; i * i <= m; ++i) {
                val = min(val, dp[m - i * i] + 1);
            }
            dp.push_back(val);
        }
        return dp.back();
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};