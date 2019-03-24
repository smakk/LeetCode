/*
Set Matrix Zeroes https://leetcode.com/problems/set-matrix-zeroes/description/

1、考虑使用第一行和第一列来记录上面所说的行和列的置0情况，这里问题是那么第一行和第一列自己怎么办？想要记录它们自己是否要置0，只需要两个变量（一个是第一行，一个是第一列）就可以了。然后就是第一行和第一列，如果要置0，就把它的值赋成0（反正它最终也该是0，无论第一行或者第一列有没有0），否则保留原值。然后根据第一行和第一列的记录对其他元素进行置0。最后再根据前面的两个标记来确定是不是要把第一行和第一列置0就可以了。这样的做法只需要两个额外变量，所以空间复杂度是O(1)
*/

    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> clos;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    clos.push_back(j);
                }
            }
        }
        
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<matrix[rows[i]].size();j++){
                matrix[rows[i]][j] = 0;
            }
        }
        
        for(int i=0;i<clos.size();i++){
            for(int j=0;j<matrix.size();j++){
                matrix[j][clos[i]] = 0;
            }
        }
    }