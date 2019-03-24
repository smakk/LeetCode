/*
一、问题描述
　　给出一个数组，按照字典顺序找出下一个排列。如果给出是最大的，则返回最小

　　例子：123，下一个比123大的排列是132

　　　　　321，这是最大的数，返回最小的数123

　　　　    115，下一个比112大的数是152

二、问题解决
　　最终要的是这个寻找下一个排列数的思路。

　　举一个例子，假设有如下数组：

　　第一步：我们从后往前遍历，寻找第一个位置i，其中i满足nums[i]<nums[i+1]，即前项数比后项数小。因为下一个排列数一定比当前数大，当数组从后往前依次递增的时候表示数是最大的，在i处数突然变小了，说明使用后面的一位比i更大的数来替换i能获得更大的排列数。

　　第二步：从i处向后寻找，找到一个比i处数更大，但是和i处数之差最小的位置j。要得到下一个排列数，一定要使换到u处的数尽可能小，但是要大于i处的数。

　　第三步：调换i和j处的数。这样确保了i处的数是最合适的。

　　第四部：对i+1到末尾的数据进行从小到大排序。最高位替换成了更大的数，故后面的数要尽可能的小，大的数要往后排。

1、注意怎么将代码写得简单，第一次遍历的时候，从size()-1到0遍历，在结尾处判断是否小于0，如果使用while循环将条件写在一起，则判断条件也会更加复杂

2、如果给定的排列是最大的，则需要返回最小排列

3、第二次寻找的时候从尾部开始寻找，这样可以减少代码复杂度，因为从头部开始寻找的时候需要额外判断所有值比目的值都大的情况。

*/

void nextPermutation(vector<int>& nums) {
    int last = INT_MIN;
    int i;
    for (i = nums.size() - 1; i >= 0; i--) {
        if (nums.at(i) < last) 
            break;
        last = nums.at(i);
    }
        //判断数据是否是最大排列数，如果是，返回最小排列数
    if (i == -1) {
        sort(nums.begin(), nums.end());
        return;
    }
    int min_pos = i;
    int min = INT_MAX;
    for (int j = i; j < nums.size(); j++) {
        if (nums.at(j) - nums.at(i)>0&& nums.at(j) - nums.at(i)< min)
            min_pos = j;
    }
    swap(nums.at(i), nums.at(min_pos));
    sort(nums.begin()+i+1,nums.end());
}

int main()
{
    vector<int> v = {2,3,1};
    nextPermutation(v);
    for (auto k : v) {
        cout << k << endl;
    }

    system("pause");
    return 0;
}