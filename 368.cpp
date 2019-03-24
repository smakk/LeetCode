/*
Largest Divisible Subset https://leetcode.com/problems/largest-divisible-subset/description/

动态规划，n的子集的个数用v[n]表示，等于之前能被整除的最大数代表的子集+1，每次i渠道一个新值，就在前面寻找所有能被该数整除的数j，v[j]表示该数的子集数

还用到了path来保存路径
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0) return vector<int>();
        sort(nums.begin(), nums.end());
    vector<int> v(nums.size(),1);
    vector<int> path(nums.size(), 0);
    int maxnum = 1;
    int maxpos = 0;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && v[i] < v[j] + 1) {
                v[i] = v[j] + 1;
                path[i] = j;
                if (v[i] > maxnum) {
                    maxnum = v[i];
                    maxpos = i;
                }
            }
        }
    }
    vector<int> result;
    for (int i = 0; i < maxnum; i++) {
        result.push_back(nums[maxpos]);
        maxpos = path[maxpos];
    }
    return result;
    }
};