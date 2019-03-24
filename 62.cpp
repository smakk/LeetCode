/*
使用动态规划，思路很清晰
使用如下代码，发现超时了
*/

int uniquePaths(int m, int n) {
    if (m == 1 || n == 1)
        return 1;
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

/*
这段代码遍历出了所有的路径，而题目只需要路径的数目。使用数组记录，关键在于怎么确定边界条件
*/

int uniquePaths2(int m, int n) {
    vector<vector<int>> result(m,vector<int>(n,1));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            result[i][j] = result[i-1][j] + result[i][j - 1];
        }
    }
    return result[m-1][n-1];
}