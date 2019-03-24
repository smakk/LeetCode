/*
一、问题描述
　　这个题目是39题的拓展，本题中，给定的数组有可能有重复元素，要求最后结果不能有重复，一个元素只能用一次。

二、问题解决
　　思路一：在向result中添加结果的时候，做一个判断去重
*/

void find2(vector<int>& candidates, int target, int begin, vector<vector<int>> &result, vector<int>& thistime) {
    if (target == 0) {
        //遍历result，看有没有和thistime相等的结果，有则直接返回
        int k;
        for (int j = 0; j < result.size(); j++) {
            if (result[j].size() == thistime.size()) {
                for (k = 0; k < thistime.size(); k++) {
                    if (thistime[k] != result[j][k])
                        break;
                }
            }
            else
                continue;
            if (k == result[j].size())
                return;
        }
        result.push_back(thistime);
        return;
    }
    for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i) {
        thistime.push_back(candidates[i]);
        find2(candidates, target - candidates[i], i+1, result, thistime);
        thistime.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> thistime;
    find2(candidates, target, 0, result, thistime);
    return result;
}

//这是测试用例
int main()
{
    vector<int> v = { 10, 1, 2, 7, 6, 1, 5 };
    vector<vector<int>> result = combinationSum2(v,8);
    for (auto i : result) {
        for (auto j : i) {
            cout << j;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}

/*
思路二：再进行添加-递归-删除操作之前做一个判断，如果是重复的，则直接跳过该值（i要改成i+1，因为本题中不允许一个元素用多次）
*/
　　std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }

    void combinationSum2(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
    }
	
/*
三、问题思考
在这题中，if (i == begin || candidates[i] != candidates[i - 1])这个判断写法很简洁，即避免了开头的判断，又可以简单去重
*/
