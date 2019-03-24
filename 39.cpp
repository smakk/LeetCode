/*
一、问题描述
　　简介概括，给定一个没有重复元素的数组，要求找出所有相加结果为target的组合（同一个元素可以多次使用，元素个数也不限）。

二、问题解决
　　使用递归，每次碰到合适的数就加入到结果之中。
*/

void find(vector<int>& candidates, int target, int begin, vector<vector<int>> &result,vector<int>& thistime) {
    if (target == 0) {
        result.push_back(thistime);
        return;
    }
    for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i) {
        thistime.push_back(candidates[i]);
        find(candidates,target-candidates[i],i,result,thistime);
        thistime.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> result;
    vector<int> thistime;
    find(candidates,target,0,result,thistime);
    return result;
}

//这是测试用例
int main()
{
    vector<int> v = {2,3,6,7};
    vector<vector<int>> result = combinationSum(v,7);
    for (auto i : result) {
        for (auto j : i)
            cout << j ;
        cout << endl;
    }

    system("pause");
    return 0;
}