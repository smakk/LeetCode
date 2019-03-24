/*
一、问题描述
　　给定一个排过序的数组，将他们重复的元素移到最后（标准库中unique的效果）,返回不重复元素的个数

　　例子：给定一个数组{1，1，2}，将数组变为{1，2，1}，返回值为2

二、问题解决
　　思路还是很简单，记录两个位置，第一个位置向前遍历，每次遇到不等的数就将他位置的数移到后一个位置上，然后前后位置加1，直到前一个位置遍历完整个数组。

1、如果前一个等于当前，代表当前值是重复，反之，如果不是则需要将当前值移位到pos处

2、边界条件，pos是从1开始，因为前一个存在的情况至少要从1开始
*/
int removeDuplicates(vector<int>& nums) {
    if (nums.size() == NULL) return 0;
    int num = nums.at(0);
    int pos = 1;
    for (int i = 1; i < nums.size(); i++) {
        while (i < nums.size() && nums.at(i) == num)
            i++;
        if (i == nums.size()) return pos;
        if (i != pos)
            nums.at(pos) = nums.at(i);
        pos++;
        num = nums.at(i);
    }
    return pos;
}

int main()
{
    vector<int> v = {1,1};
    cout << removeDuplicates(v) << endl;

    system("pause");
    return 0;
}

/*
上面的代码还是很繁琐，不容易看出逻辑。Leetcode里面讨论有一个很简洁的实现，可以看一波
*/
public int removeDuplicates(int[] nums) {
    if (nums.length == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.length; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}