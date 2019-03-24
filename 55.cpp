/*
一、问题描述
　　给定一个数组nums，给定一个非负整数数组, 您最初定位在数组的第一个索引处。数组中的每个元素表示该位置上的最大跳转长度。确定是否能够到达最后一个索引。

例子：

A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

二、问题解决
1、暴力解法，一步一步尝试，用递归来解决。
*/

//该函数的意义是从nums的pos位置往后能不能到达最后一个位置
bool jump(vector<int>& nums, int pos) {
    if (pos >= nums.size() - 1) return true;
    for (int i = nums[pos]; i > 0; i--) {
        //当nums[pos]为0的时候不能往下跳，会陷入死循环，所以这里有这个判断
        if (nums[pos] == 0)
            continue;
        if (jump(nums, pos + i) == true)
            return true;
    }
    return false;
}
bool canJump(vector<int>& nums) {
    return jump(nums,0);
}

/*
 2、贪心算法，寻找最大可到达的距离，然后看该距离是否大于数组长度
*/

bool canJump(vector<int>& nums) {
    //dis表示在i之前位置所能到达的最远距离
    int dis = 0;
    //i<=dis这个条件保障了i这个位置是可以通过i之前的位置到达
    for (int i = 0; i < nums.size() && i <= dis; i++)
        dis = max(nums[i]+i,dis);
    if (dis < nums.size() - 1)
        return false;
    return true;
}

