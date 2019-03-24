/*
寻找一个数组中最大子片段

Maximum Subarray https://leetcode.com/problems/maximum-subarray/description/
*/

    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int current = 0;
        for(int i =0;i<nums.size();i++){
            current = current + nums[i];
            if(current > max)
                max = current;
            if(current < 0)
                current = 0;
        }
        return max;
    }