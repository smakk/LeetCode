/*
一、问题描述
　　给定一个数组S，和一个int类型的数target，在S中寻找四个数，这四个数之和为target。返回一个vector<vector<int>>

　　例子：S={1, 0, -1, 0, -2, 2}，target = 0.返回结果为{{-1，0，0，1}，{-2，1，1，2}，{-2，0，0，2}}

二、问题解决
　　最简单的思路是四层循环，这样不管是之前的3之和问题还是4之和问题都能解决，缺点就是比较费时，在leetcode上提交还可能超时。

　　更好一点的方式是对数组进行排序之后，从两边逼近的方式。这样可以减少一层循环，3数之和就先确定一个数，4数之和就先确定两个数。本题下面的解法之中，固定i和j，让k和l冲两边逼近。

　　这题比较麻烦的是去重复。
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4) return result;
    sort(nums.begin(),nums.end());
    /*
    for (auto o : nums)
        cout << o;
    cout << endl;
    */
    for (int i = 0; i < nums.size() - 3; i++) {
　　　　　//去除重复
        while (i != 0  && nums.at(i - 1) == nums.at(i))
            i++;
        for (int j = i + 1; j < nums.size() - 2; j++) {
　　　　　　　//去除重复
            while (j != i + 1 && j+1 <nums.size()-1&& nums.at(j-1) == nums.at(j))
                j++;
            int k = j + 1, l = nums.size()-1;
            while (k < l) {
                //cout << i << j << k << l << endl;
                if (nums.at(i) + nums.at(j) + nums.at(k) + nums.at(l) == target) {
                    vector<int> temp;
                    temp.emplace_back(nums.at(i));
                    temp.emplace_back(nums.at(j));
                    temp.emplace_back(nums.at(k));
                    temp.emplace_back(nums.at(l));
                    result.emplace_back(temp);
　　　　　　　　　　　　//去除重复
                    while (k + 1 < l && nums.at(k) == nums.at(k + 1))
                        k++;
                    while (l-1 > k && nums.at(l) == nums.at(l - 1))
                        l--;
                    k++;
                }
                if (nums.at(i) + nums.at(j) + nums.at(k) + nums.at(l) > target)
                    l--;
                if (nums.at(i) + nums.at(j) + nums.at(k) + nums.at(l) < target)
                    k++;
            }
        }
    }
    //result.erase(unique(result.begin(), result.end()),result.end());
    return result;
}