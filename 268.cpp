/*
Missing Number https://leetcode.com/problems/missing-number/description/

优化方法、将所有值和0-9全部异或一遍，如果重复出现则一定清0、求和再相见
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i)
                return i;
        }
        return nums.size();
    }
};

