/*
一、题目描述
　　给定一个int类型的数组，找出其中的3个元素a，b，c，使a+b+c=0。找出所有的这样的三元组

　　exapmle：

　　给定数组：S = [-1, 0, 1, 2, -1, -4]

　　返回值：

　　[
  　　[-1, 0, 1],
　　  [-1, -1, 2]
　　]

二、题目解答
　　先进行排序，然后确定第一个数的位置，剩下两个位置采用两边逼近的方式。

1、在找到合适的组合之后需要一定一个索引值，不然循环就不能继续了

2、注意怎样去除重复值
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int i = 0;
    int last = nums.size() - 1;
    while (i < last) {
        int a = nums[i];
        int j = i + 1;
        int k = last;
        while (j < k) {
            int b = nums[j];
            int c = nums[k];
            int sum = a + b + c;
            if (sum == 0)
                result.push_back({a,b,c});
            if (sum <= 0)
                while (nums[j] == b && j < k)
                    j++;
            if (sum >= 0)
                while (nums[k] == c && j < k)
                    k--;
        }
        while (nums[i] == a && i < last)
            i++;
    }
    return result;
}