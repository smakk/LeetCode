/*
Product of Array Except Self https://leetcode.com/problems/product-of-array-except-self/description/

关键在于能否想出0的情况 
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long mul = 1;
        int zero = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                mul = mul*nums[i];
            }else{
                zero++;
            }
        }
        vector<int> result(nums.size(),0);
        if(zero >= 2)
            return result;
        for(int i =0;i<result.size();i++){
            if(zero !=0 && nums[i]!=0){
                result[i] != 0;
                continue;
            }else if(zero !=0 && nums[i] == 0){
                result[i] = mul;
                continue;
            }
            result[i] = mul/nums[i];
        }
        return result;
    }
};

