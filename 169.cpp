/*
Majority Element https://leetcode.com/problems/majority-element/description/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major = 0;
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                count++;
                major = nums[i];
            }else{
                if(nums[i] == major){
                    count++;
                }else{
                    count--;
                }
            }
        }
        return major;
    }
};