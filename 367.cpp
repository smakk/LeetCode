/*
Valid Perfect Square https://leetcode.com/problems/valid-perfect-square/description/
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(int(sqrt(num))*int(sqrt(num)) == num)
            return true;
        else 
            return false;
    }
};