/*
一、问题描述
　　这是问题33的升级版，在数组中有重复元素。

二、问题解决
　　思路和问题33一样，不同点在于判断nums[left]==nums[middle]的时候不能得出左右哪个是单调递增，哪个是循环递增。这时候简单递增一下left，应为此时left一定不为target，可以使代码进一步往下运行。
*/

/*
和33相比，只有18行和19行多了一个等于时的条件判断，然后前面把等于的条件去掉了，调整了if esle。
*/

bool search_duplicates(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (nums[middle] == target)
            return true;
        if (nums[middle] > nums[left])
            if (target <= nums[middle] && nums[left] <= target)
                right = middle - 1;
            else
                left = middle + 1;
        else if (nums[middle] < nums[left])
            if (target >= nums[middle] && nums[right] >= target)
                left = middle + 1;
            else
                right = middle - 1;
        else
            left++;
    }
    return false;
}

int main()
{
    vector<int> v = { 4, 5, 6, 7,7, 0, 1, 2 };
    cout << search(v, 7) << endl;

    system("pause");
    return 0;
}

