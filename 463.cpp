/*
Island Perimeter https://leetcode.com/problems/island-perimeter/description/
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int result = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    if(i-1<0 || grid[i-1][j]==0){
                        ++result;
                    }
                    if(j-1<0 || grid[i][j-1]==0){
                        ++result;
                    }
                    if(i+1==grid.size() || grid[i+1][j]==0){
                        ++result;
                    }
                    if(j+1==grid[0].size() || grid[i][j+1]==0){
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};