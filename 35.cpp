/*
　　应该是很简单了。4行代码解决。
*/
int searchInsert(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] >= target)
            return i;
    return nums.size();
}

int main()
{
    vector<int> v = { 1,3,5,6 };
    cout << searchInsert(v, 0) << endl;

    system("pause");
    return 0;
}