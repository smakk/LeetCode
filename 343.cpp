/*
Integer Break https://leetcode.com/problems/integer-break/description/
*/

class Solution {
public:
    int integerBreak(int n) {
        int result = 1;

        if (n <= 4) 
            return n == 4? 4: n-1;

        while (n > 4) {
            result *= 3;
            n -= 3;
        }

        return result * n;
    }
};