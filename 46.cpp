/*
一、问题描述
　　就是全排列问题。

二、问题解决
　　应该哪一本数据结构的书上都有讲了。
*/

void get_permute(vector<int>& nums, int pos, vector<vector<int>>& result) {
    if (nums.size() == pos) {
        result.push_back(nums);
        return;
    }
    for (int i = pos; i < nums.size(); i++) {
        swap(nums[pos], nums[i]);
        get_permute(nums,pos+1,result);
        swap(nums[i], nums[pos]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    get_permute(nums,0,result);
    return result;
}