/*
Find All Numbers Disappeared in an Array https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int pos = abs(nums[i]) -1;
            nums[pos] = abs(nums[pos])*-1;
        }
        for(int i =0;i<nums.size();i++){
            if(nums[i] >0) result.push_back(i+1);
        }
        return result;
    }
};