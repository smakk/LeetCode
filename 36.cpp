/*
一、问题描述
　　判断一个不完整的数独是否正确。
　　判断数独是否正确的条件：1、每行的数不重复。2、没列的数不重复。3、划分成的9个3*3的块中没有数重复。
　　例子看下面代码中的测试用例。

二、问题解决
　　思路一：分3次循环来解决，第一次横向遍历，第二次纵向遍历，第三次以块遍历。每一次遍历一行、一列、或是一块的时候使用map记录每个数出现的次数，当出现两次的时候返回false
*/

bool isValidSudoku(vector<vector<char>>& board) {
    for (auto i : board) {
        map<char, int> map = { { '1',0 },{ '2',0 },{ '3',0 },{ '4',0 },
        { '5',0 },{ '6',0 },{ '7',0 },{ '8',0 },{ '9',0 }, };
        for (auto j : i) {
            if (j == '.') continue;
            if (map[j] == 0)
                map[j]++;
            else
                return false;
        }
        map = { { '1',0 },{ '2',0 },{ '3',0 },{ '4',0 },
        { '5',0 },{ '6',0 },{ '7',0 },{ '8',0 },{ '9',0 }, };
    }

    for (int i = 0; i < 9; i++) {
        map<char, int> map = { { '1',0 },{ '2',0 },{ '3',0 },{ '4',0 },
        { '5',0 },{ '6',0 },{ '7',0 },{ '8',0 },{ '9',0 }, };
        for (int j = 0; j < 9; j++) {
            if (board[j][i] == '.') continue;
            if (map[board[j][i]] == 0)
                map[board[j][i]]++;
            else
                return false;
        }
        map = { { '1',0 },{ '2',0 },{ '3',0 },{ '4',0 },
        { '5',0 },{ '6',0 },{ '7',0 },{ '8',0 },{ '9',0 }, };
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            map<char, int> map = { { '1',0 },{ '2',0 },{ '3',0 },{ '4',0 },
            { '5',0 },{ '6',0 },{ '7',0 },{ '8',0 },{ '9',0 }, };
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    int posx = m + i * 3;
                    int posy = n + j * 3;
                    if (board[posx][posy] == '.') continue;
                    if (map[board[posx][posy]] == 0)
                        map[board[posx][posy]]++;
                    else
                        return false;
                }
            }
            map = { { '1',0 },{ '2',0 },{ '3',0 },{ '4',0 },
            { '5',0 },{ '6',0 },{ '7',0 },{ '8',0 },{ '9',0 }, };
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> v = {{'.', '.', '.', '.', '5', '.', '.', '1','.'},
                            { '.', '4', '.', '3', '.', '.', '.', '.', '.' },
                            { '.', '.', '.', '.', '.', '3', '.', '.', '1' },
                            { '8', '.', '.', '.', '.', '.', '.', '2', '.' },
                            { '.', '.', '2', '.', '7', '.', '.', '.', '.' },
                            { '.', '1', '5', '.', '.', '.', '.', '.', '.' },
                            { '.', '.', '.', '.', '.', '2', '.', '.', '.' },
                            { '.', '2', '.', '9', '.', '.', '.', '.', '.' },
                            { '.', '.', '4', '.', '.', '.', '.', '.', '.' } };
    cout << isValidSudoku(v) << endl;

    system("pause");
    return 0;
}

/*
思路二：更简洁方便的解决
*/
bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
	
/*
在判断是否出现重复的时候使用9*9的数组来表示，而不是使用map。遍历一遍就ok了。在利用i和j计算块内索引的时候很巧妙，记住这种方法。
*/
