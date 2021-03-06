/*
Intersection of Two Arrays https://leetcode.com/problems/intersection-of-two-arrays/description/
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums1.size();i++){
            hash[nums1[i]]++;
        }
        vector<int> result;
        for(int i=0;i<nums2.size();i++){
            if(hash[nums2[i]] != 0){
                result.push_back(nums2[i]);
                hash[nums2[i]] = 0;
            }
        }
        return result;
    }
};