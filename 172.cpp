/*
Factorial Trailing Zeroes https://leetcode.com/problems/factorial-trailing-zeroes/description/
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
    for (long long t = 5; t <= n; t= t*5) {
        result += n / t;
    }
    return result;
    }
};
