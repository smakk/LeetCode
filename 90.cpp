/*
Subsets II https://leetcode.com/problems/subsets-ii/description/

1、重复的地方在与多个重复元素在一起的时候会出现前一个在、后一个不再和前一个不在、后一个在的这种重复情况，想要去除就在遇到这种情况的时候直接跳过，用不重复的情况代替，不重复的情况是确定个数的重复元素
*/

void getsubsetsWithDup(vector<int>& nums, int pos, vector<int>& temp, vector<vector<int>>& result) {
    if (pos == nums.size()) {
        result.emplace_back(temp);
        return;
    }
    //nextpos指向下一个不为nums[pos]的位置或为nums.size()
    int nextpos = pos + 1;
    while (nextpos != nums.size() && nums[nextpos] == nums[pos])
        nextpos++;
    getsubsetsWithDup(nums, nextpos, temp, result);
    for (int i = pos; i < nextpos; i++) {
        temp.emplace_back(nums[i]);
        getsubsetsWithDup(nums, nextpos, temp, result);
    }
    temp.erase(temp.end() - (nextpos - pos), temp.end());
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> temp;
    getsubsetsWithDup(nums, 0, temp, result);
    return result;
}
