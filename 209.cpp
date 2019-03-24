/*
Minimum Size Subarray Sum https://leetcode.com/problems/minimum-size-subarray-sum/description/

二分查找的思路，先使用一个单调递增的数列来存储开头到当前位置的长度和（数组项全为正数），每次使用二分法寻找第一个大于sum[i]+s的位置，也就是最小长度。代码写法可以好好的参考一下。
*/

	int n = nums.size();
    if (n == 0)
        return 0;
    int ans = INT_MAX;
    vector<int> sums(n + 1, 0); //size = n+1 for easier calculations
    //sums[0]=0 : Meaning that it is the sum of first 0 elements
    //sums[1]=A[0] : Sum of first 1 elements
    //ans so on...
    for (int i = 1; i <= n; i++)
        sums[i] = sums[i - 1] + nums[i - 1];
    for (int i = 1; i <= n; i++) {
        int to_find = s + sums[i - 1];
        auto bound = lower_bound(sums.begin(), sums.end(), to_find);
        if (bound != sums.end()) {
            ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
        }
    }
    return (ans != INT_MAX) ? ans : 0;
	
//维护一个值大于s的序列，向前加一个数的时候，再从尾部减去直到序列小于s，然后又向前读取数组直到大于s
//1、边界条件当数组所有元素和都小于s的时候需要特殊处理
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT_MAX;
        int pos = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            while(sum>=s){
                result = min(i-pos+1,result);
                sum = sum - nums[pos++];
            }
        }
        if(result == INT_MAX)
            return 0;
        return result;
    }
};
