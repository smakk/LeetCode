/*
一、问题描述
　　全排列问题的升级，给定数组有重复元素，要求输出结果无重复元素。
二、问题解决
　　考虑全排列问题重复的情况。按照全排列的递归思想。重复情况有两种，第一种是开始位置和交换位置重复，第二种是交换位置和交换位置之后的元素有重复。见代码。
*/

void get_permuteUnique(vector<int>& nums, int pos, vector<vector<int>>& result) {
    if (nums.size() == pos) {
        result.push_back(nums);
        return;
    }
    for (int i = pos; i < nums.size(); i++) {
        //第一种重复，位置pos和位置i的数重复
        if (i != pos && nums[i] == nums[pos]) continue;
        //第二种重复，位置pos和位置i的数不重复
        //但pos之后有两个位置i和j，nums[i]和nums[j]有重复,导致pos和同一个数交换了两次
        bool find = false;        //用find来指示是否找到了这样的i和j
        if(i != pos){
            int temp = i;
            while (temp < nums.size()) {
                if (temp != i && nums[temp] == nums[i]) {
                    find = true;
                    break;
                }
                temp++;
            }
        }
        if (find == true)
            continue;
        //除去重复结束

        swap(nums[pos], nums[i]);
        get_permuteUnique(nums, pos + 1, result);
        swap(nums[i], nums[pos]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    get_permuteUnique(nums, 0, result);
    return result;
}

//这是测试用例
int main()
{
    vector<int> v = {1,1,3};
    auto result = permuteUnique(v);
    for (auto i : result) {
        for (auto j : i)
            cout << j;
        cout << endl;
    }

    system("pause");
    return 0;
}