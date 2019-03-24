/*
Majority Element II https://leetcode.com/problems/majority-element-ii/description/ 

2题的思路一样，使用1个计数器或是2个计数器，遍历一个元素就从中删除其他两个元素的计数
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int major1 = 0;
        int major2 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(count1 != 0 && major1 == nums[i]){count1++;continue;}
            if(count2 != 0 && major2 == nums[i]){count2++;continue;}
            if(count1 == 0){major1 = nums[i];count1++;continue;}
            if(count2 == 0){major2 = nums[i];count2++;continue;}
            count1--;
            count2--;
        }
        int num1 = count1;
        int num2 = count2;
        count1 = 0;
        count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(num1>0){
                if(nums[i] == major1) count1++;
            }
            if(num2>0){
                if(nums[i] == major2) count2++;
            }
        }
        if(count1>nums.size()/3) result.push_back(major1);
        if(count2>nums.size()/3) result.push_back(major2);
        return result;
    }
};