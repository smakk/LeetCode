/*
 Subsets https://leetcode.com/problems/subsets/description/
*/

    void subsets(vector<int>& nums, int pos, vector<int>& current, vector<vector<int>>& result){
        if(pos == nums.size()){
            result.push_back(current);
            return;
        }else{
            subsets(nums,pos+1,current,result);
            current.push_back(nums[pos]);
            subsets(nums,pos+1,current,result);
            current.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        subsets(nums, 0, current, result);
        return result;
    }