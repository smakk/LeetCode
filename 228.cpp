/*
Summary Ranges https://leetcode.com/problems/summary-ranges/description/
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for(int i=0;i<nums.size();i++){
            int begin = nums[i];
            while(i != nums.size()-1 && nums[i]+1 == nums[i+1]){
                i++;
            }
            int end = nums[i];
            if(begin != end){
                result.push_back(to_string(begin) + "->" + to_string(end));
            }else{
                result.push_back(to_string(begin));
            }
        }
        return result;
    }
};