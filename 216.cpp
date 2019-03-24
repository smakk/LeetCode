/*
216. Combination Sum III https://leetcode.com/problems/combination-sum-iii/description/
*/

class Solution {
public:
    /*
        pos：遍历到1到9中的哪个位置
        current：当前的数组
    */
    void combinationSum3(vector<vector<int>>& result, int k ,int n, int pos,vector<int>& current){
        if(n == 0 && k== 0){
            result.push_back(current);
            return;
        }else if(n <= 0 || k <= 0 || pos > 9)
            return;
        else{
            for(int i=pos;i<=9;i++){
                if(n-i<0) return;
                current.push_back(i);
                combinationSum3(result,k-1,n-i,i+1,current);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        combinationSum3(result, k, n, 1, current);
        return result;
    }
};