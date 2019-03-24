/*
一、问题描述
　　一个有序数组，将它截成两部分，然后两部分换位置，得到数组nums。比如对于01234567这个数组，分成012和4567这两个部分，然后把这两个部分调换位置，012放在后，4567放在前，假设得到的数组为nums。

二、问题解决
　　思路一：最简单的遍历一遍，找到和target相等的数，返回索引值。这样可定能解，经测试也没有超时，但是题目的意思肯定是使用更高效率的方法。
*/

int search(vector<int>& nums, int target) {
    for (int i = 0; i<nums.size(); i++)
        if (nums.at(i) == target)
            return i;
    return -1;
}

int main()
{
    vector<int> v = {4,5,6,7,0,1,2};
    cout << search(v,6) << endl;;

    system("pause");
    return 0;
}

/*
思路二：使用二分法查找，由于数组并不是一味的单调递增，还会有循环递增的可能，所以在进行区间选择的时候需要额外的判断条件。

第一步：确定两边区间的递增性。每一次取得中间节点，使用中间节点和两区间端点进行比较，如果middle>left，则左边是单调递增数组，右边是循环递增数组，如果middle<left，则左边是循环递增数组，右边单调递增数组。

第二步：确定target位置。前一步判断出两边区间的递增性，根据两种不同情况再考虑target的位置。

情况1，左边是单调递增区间，右边是循环递增区间：target<middle,且left<target，则在左区间。否则在右区间

情况2，右边是循环递增区间，左边是单调递增区间：target>middle,且right>target,则在右区间，否则在左区间
*/

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (nums[middle] == target)
            return middle;
        if (nums[middle] >= nums[left]) 
            if (target <= nums[middle] && nums[left] <= target) 
                right = middle - 1;
            else
                left = middle + 1;
        else
            if (target >= nums[middle] && nums[right] >= target) 
                left = middle + 1;
            else 
                right = middle - 1;
    }
    return -1;
}

/*
问题中使用的二分法必须非常熟悉，不能要用的时候再思考，边界条件都是大于等于或小于等于。等于不能忘记。本题是二分查找的一种变形。
*/