/*
Third Maximum Number https://leetcode.com/problems/third-maximum-number/description/

如何处理越界的问题
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
    long long m1 = (long long)INT_MIN - 1;
    long long m2 = (long long)INT_MIN - 2;
    long long m3 = (long long)INT_MIN - 3;
    int times = 0;
    for (int i = 0; i<nums.size(); i++) {
        if (nums[i]>m1) {
            times++;
            m3 = m2;
            m2 = m1;
            m1 = nums[i];
        }
        else if (nums[i]<m1 && nums[i]>m2) {
            times++;
            m3 = m2;
            m2 = nums[i];
        }
        else if (nums[i]<m2 && nums[i]>m3) {
            times++;
            m3 = nums[i];
        }
    }
    if(times < 3)
        return m1;
    return m3;
}
};
