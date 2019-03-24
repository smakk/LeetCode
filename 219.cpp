/*
Contains Duplicate II https://leetcode.com/problems/contains-duplicate-ii/description/
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]] != 0 && (i-map[nums[i]]+1)<=k)
                return true;
            else
                map[nums[i]] = i+1;
        }
        return false;
    }
};