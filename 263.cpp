/*
Ugly Number https://leetcode.com/problems/ugly-number/description/
*/

class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        while(num!=1){
            bool div = false;
            if(num%2==0){
                num = num/2;
                div = true;
            }
            if(num%3==0){
                num = num/3;
                div = true;
            }
            if(num%5==0){
                num = num/5;
                div = true;
            }
            if(div==false)
                return false;
        }
        return true;
    }
};