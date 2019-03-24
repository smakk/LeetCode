/*
1、递归
　　维持一个开始位置和当前集合，每次进行加入开始位置的元素再递归、不加入就递归两种操作，代表这个元素是否出现在该集合之中
*/

class Solution {
public:
    void subsets(vector<int>& nums, int pos, vector<int>& current, vector<vector<int>>& result){
        if(pos == nums.size()){
            result.push_back(current);
            return;
        }else{
            subsets(nums,pos+1,current,result);
            current.push_back(nums[pos]);
            subsets(nums,pos+1,current,result);
            current.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        subsets(nums, 0, current, result);
        return result;
    }
};

/*
2、迭代
　　思路是从头往后遍历数组，每次遍历到一个新的成员，就将他和前面每一个集合并一下得到一连串新的集合，将这些集合加入再次做运算。

Initially: [[]]
Adding the first number to all the existed subsets: [[], [1]];
Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]); 
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
}; 

/*
3、位图
　　思路是先创建出2^n个数组，第一个元素每个2个子集出现一个，第二个隔4个、依次类推下去。用位图来判断当前集合是否该出现某个元素
	1. [], [], [], [], [], [], [], []
    2. [], [1], [], [1], [], [1], [], [1]
	3. [], [1], [2], [1, 2], [], [1], [2], [1, 2]
	4.[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = pow(2, nums.size()); 
        vector<vector<int>> subs(n, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < n; j++) {
                if ((j >> i) & 1) {
                    subs[j].push_back(nums[i]);
                }
            }
        }
        return subs;
    }
};