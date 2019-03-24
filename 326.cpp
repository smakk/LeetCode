/*
Power of Three https://leetcode.com/problems/power-of-three/description/
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        while(n%3==0){
            n = n/3;
        }
        if(n==1) return true;
        else return false;
    }
};