/*
Add Digits https://leetcode.com/problems/add-digits/description/
*/

class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int result = 0;
            while(num>0){
                result = result + num%10;
                num = num/10;
            }
            num = result;
        }
        return num;
    }
};