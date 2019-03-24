/*
Triangle https://leetcode.com/problems/triangle/description/

动态规划，从底部可以简化代码很多
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j+1],triangle[i+1][j]);
            }
        }
        return triangle[0][0];
    }
};