/*
Sort Colors https://leetcode.com/problems/sort-colors/discuss/26474/Sharing-C++-solution-with-Good-Explanation

思路是维持两个位置，分别为0的结束位置和2的开始位置，遍历时如果碰到0则和前面的位置交换，碰到2则和后面的位置交换

在mid和first交换的时候需要将mid和first同时++，而不是只++mid,因为在pos0到pos1这段是只有1的，因为0被交换到前面，2被交换到后面
*/

    void sortColors(vector<int>& nums) {
        int pos0 = 0;
        int pos1 = 0;
        int pos2 = nums.size()-1;
        while(pos1<=pos2){
            if(nums[pos1] == 0){
                swap(nums[pos0], nums[pos1]);
                ++pos0;
                ++pos1;
            }else if(nums[pos1] == 2){
                swap(nums[pos1], nums[pos2]);
                --pos2;
            }else{
                ++pos1;
            }
        }
    }
	