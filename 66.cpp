/*
Plus One https://leetcode.com/problems/plus-one/description/
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        for(;i>=0;i--){
            if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i] = digits[i]+1;
                break;
            }
        }
        if(i == -1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};