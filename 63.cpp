/*
和上一题一样，递归会超时
*/

//63 不同路径2,递归解法
int uniquePaths2(vector<vector<int>>& obstacleGrid, int m,int n) {
    if ((m == 1 && n == 2) || (m == 2 && n == 1) || (m == 1 && n == 1)) {
        if (obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 0)
            return 1;
        else
            return 0;
    }
    int p1 = 0;
    int p2 = 0;
    //获得向下走的总数,当下面的数为1或者是到了最底层,向下的总数为0
    if (m == 1 || obstacleGrid[m-2][n-1] == 1 )
        p1 = 0;
    else
        p1 = uniquePaths2(obstacleGrid,m-1,n);
    //向右
    if (n == 1 || obstacleGrid[m -1 ][n - 2] == 1 )
        p2 = 0;
    else
        p2 = uniquePaths2(obstacleGrid, m, n - 1);
    return p1 + p2;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == 1)
        return 0;
    return uniquePaths2(obstacleGrid,obstacleGrid.size(),obstacleGrid[0].size());
}

/*
使用数组可以通过，和上题相比，这题思路就更直接，但是效率比之前更低一点，使用的result和题目所给的格子大小一样，从右下向左上遍历，更加清晰，就是需要额外处理终点
*/

//非递归解法
int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
    /*if (obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1])
        return 0;*/
    vector<vector<int>> result(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
    for (int i = obstacleGrid.size() - 1; i >= 0; i--) {
        for (int j = obstacleGrid[0].size() - 1; j >= 0; j--) {
            if (obstacleGrid[i][j] == 1) {
                result[i][j] = 0;
                continue;
            }
            if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
                result[i][j] = 1;
                continue;
            }
            int p1 = 0;
            int p2 = 0;
            //如果是下部有位置
            if (i != obstacleGrid.size() - 1)
                p1 = result[i + 1][j];
            //如果是右边有位置
            if (j != obstacleGrid[0].size() - 1)
                p2 = result[i][j + 1];
            result[i][j] = p1 + p2 ;
        }
    }
    return result[0][0];
}
}