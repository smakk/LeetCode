/*
问题描述
给定一个整数数组，找到一个具有最大和的子数组，返回其最大和。

问题解析
很经典的一个问题，下面给出3种解法，暴力解法、分治算法、动态规划。这个题Leetcode上有大量测试数据，只不过最后两个测试数据要求算法复杂度为n，只能用动态规划来解，可以借鉴一下，链接见这里https://leetcode.com/problems/maximum-subarray/description/

问题解决
1、暴力解法

穷举所有的子串，计算他们的和，然后从中找出最大的一个。
*/

//最大子数组的暴力解法
int maxSubArray1(vector<int>& nums) {
    int max = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
            int temp = 0;
            for (int k = i; k < j; ++k) {
                temp += nums[k];
            }
            if (temp > max)
                max = temp;
        }
    }
    return max;
}

/*
2、分治算法
首先，将数组从中间分为两个部分
在此基础上我们考虑最大子串的情况，最大最子串的位置可能有两种：
第一种，只在Part1或是Part2之中，不跨越中间线。这种情况直接采用递归求出
第二种，跨越中间线。这种情况要寻找最大子串，我们从中间线开始，向左右两侧拓展，分别找到左侧最大值和右侧最大值，然后相加。
例如，所给数组为{ -2,1,-3,4,-1,2,1,-5,4 }，中间位置为-1处，要求跨越中间线的最大子串，我们从-1开始向左遍历，得到子串{4，-1}、{-3，4，-1}、{1，-3，4，-1}和{-2,1,-3,4,-1}找出左侧最大子串{4，-1}。然后向右遍历，依次得到{-1，2}、{-1，2，1}、{-1，2，1，-5}、{-1，2，1，-5，4}，其中右侧最大子串为{-1，2，1}，最后将左侧最大子串和右侧最大子串相加即可。
*/

//最大子数组的分治解法
int maxstr(vector<int>& nums,int left,int right) {
    //递归停止条件
    if (left == right)
        return nums[left];
    int mid = (left + right) / 2;
    //左侧递归
    int leftmax = maxstr(nums,left,mid);
    //右侧递归
    int rightmax = maxstr(nums,mid + 1, right);
    //从中间线向左寻找
    int lmax INT_MIN;
    int l = 0;
    for (int i = mid; i >= 0; --i) {
        l += nums[i];
        if (l > lmax)
            lmax = l;
    }
    //从中间线向右寻找
    int rmax = INT_MIN;
    int r = 0;
    for (int i = mid; i <= right; ++i) {
        r += nums[i];
        if (r > rmax)
            rmax = r;
    }
    int midmax = lmax + rmax -nums[mid];
    return  leftmax > rightmax?max(leftmax,midmax):max(rightmax,midmax);
}
int maxSubArray2(vector<int>& nums) {
    return maxstr(nums,0,nums.size()-1);
}

/*
3、动态规划
这也是效率最高的一种办法，只需要遍历一遍，但思路有些难理解。
假设一个串a>0，那么这个串加上另一个串b一定比b要大，按照这个思路，从第一个数开始累加，如果累加之和小于0，则弃掉之前的数，从数组之后的位置重新开始累加，知道数组遍历完成，找出其中最大的数。（由于被弃掉时一定是遇到了一个绝对值大于前面所有正数的负数串，所以最大子串一定不能包含该负数串，因为在加上该负数串之前的串一定更大）
*/

//最大子数组的动态规划解法
int maxSubArray3(vector<int>& nums) {
    int max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum > max)
            max = sum;
        if (sum < 0)
            sum = 0;
    }
    return max;
}