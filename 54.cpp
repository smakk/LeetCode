/*
一、问题描述
　　给定一个矩阵、要求螺旋型输出矩阵结果。

　　例子：给定矩阵[[1,2,3],[4,5,6],[7,8,9]]。输出结果为1,2,3,6,9,8,7,4,5。

二、问题解决
　　将矩阵分解成多个嵌套的空心矩形来遍历，将每个空心矩形的遍历分为四个部分：向右增长，向下增长，向左增长，向上增长。（代码中令direct等于1，2，3，4来表示这四个方向）

　　用distance来表示某一个空心矩形遍历时，转向位置距离矩阵最外层边的距离，注意这个遍历在向左增长完之后加1，应为画一个空心矩形时，向上增长的尽头为向右增长的起始点，而不是矩阵边框。

　　其他变量都很好理解了。

	1、代码中的循环使用xy，左边方式和数组寻址的位置正好相反

	2、在每次循环之后，x或y的值都会偏移到end之后，所以需要更正

	3、循环之后还要调整坐标，让下一个方向的遍历不会加入重复元素 
*/


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.size() == 0) return result;
    int direct = 1;
    int distance = 0;
    int posx = 0;
    int posy = 0;
    bool directchange = false;
    int step = 0;
    result.push_back(matrix[posy][posx]);
    while (true) {
        if (direct == 1) {
            if (posx + distance < matrix[0].size() - 1) 
                posx++;
            else {
                directchange = true;
                direct++;
            }
        }
        else if (direct == 2) {
            if (posy + distance < matrix.size() - 1) 
                posy++;
            else {
                directchange = true;
                direct++;
            }
        }
        else if (direct == 3) {
            if (posx > distance)
                posx--;
            else {
                directchange = true;
                direct++;
                distance++;
            }
        }
        else if (direct == 4) {
            if (posy > distance) 
                posy--;
            else {
                directchange = true;
                direct = 1;
            }
        }
        if (directchange == false) {
            result.push_back(matrix[posy][posx]);
            step++;
        }
        else
            directchange = false;
        if (step == matrix.size() * matrix[0].size()-1)
            break;
    }
    return result;
}

//这是测试用例
int main()
{
    vector<vector<int>> v = { {1,2,3},{4,5,6},{7,8,9} };
    for (auto i : spiralOrder(v))
        cout << i << endl;

    system("pause");
    return 0;
}
