/*
Find Minimum in Rotated Sorted Array https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int pos1 = 0;
        int pos2 = nums.size()-1;
        while(pos1<pos2){
            int middle = (pos1+pos2)/2;
            if(nums[pos1]<=nums[middle] && nums[middle]<nums[pos2]){
                return nums[pos1];
            }else if(nums[middle] < nums[pos2] && nums[pos2]<nums[pos1]){
                pos2 = middle;
            }else{
                pos1 = middle+1;
            }
        }
        return nums[pos1];
    }
};