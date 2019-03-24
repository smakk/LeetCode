/*
一、问题描述
　　给定一个数n，将它螺旋形填入n*n的矩阵之中

　　例子：n=3

　　输出矩阵：[[1,2,3]

　　　　　　　[8,9,4]

　　　　　　　[7,6,5]]　　

二、问题解决
　　具体思路见这里，只是将输出该为赋值，代码重新整理了一下，思路清晰多了。
*/

vector<vector<int>> generateMatrix(int n) {
    //先根据n创建这样的矩阵出来
    vector<vector<int>> result;
    if (n == 0) return result;
    for (int i = 0; i < n; i++) {
        vector<int> temp(n,0);
        result.push_back(temp);
    }
    //然后螺旋形放入数组之中
    //和边界的距离
    int distance = 0;
    //将要填到数组中的数是多少
    int pos = 1;
    //将要填到数组中的哪个位置
    int posx = 0;
    int posy = 0;
    //方向，依次为上、又、下、左
    enum direct {top,right,buttom,left} dir = top;
    //现将第一个数填进去
    result[0][0] = pos;
    pos++;
    while (pos <= n*n) {
        //向右走时
        if (dir == top) {
            result[posy][++posx] = pos++;
            if (posx + distance == n - 1)
                dir = right;
        }
        //向下走时
        else if (dir == right) {
            result[++posy][posx] = pos++;
            if (posy + distance == n - 1)
                dir = buttom;
        }
        //向左走时
        else if (dir == buttom) {
            result[posy][--posx] = pos++;
            if (posx == distance) {
                dir = left;
                ++distance;
            }
        }
        //向上走时
        else if (dir == left) {
            result[--posy][posx] = pos++;
            if (posy == distance)
                dir = top;
        }
    }
    return result;
}

//这是测试用例
int main()
{
    auto result = generateMatrix(3);
    for (auto i : result) {
        for (auto j : i)
            cout << j;
        cout << endl;
    }

    system("pause");
    return 0;
}