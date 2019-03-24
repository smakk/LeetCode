/*
Remove Duplicates from Sorted Array II https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int pos1 = 1;
        int repeat = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1] && repeat == 1){
                continue;
            }else if(nums[i] == nums[i-1] && repeat != 1){
                ++repeat;
            }else{
                repeat = 0;
            }
            nums[pos1++] = nums[i];
        }
        return pos1;
    }
};