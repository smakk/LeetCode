/*
Pascal's Triangle II https://leetcode.com/problems/pascals-triangle-ii/description/

既然正向会覆盖，则逆向来赋值
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1);
        for(int i=3;i<=rowIndex+1;i++){
            for(int j=i-2;j>0;j--){
                result[j] = result[j]+result[j-1];
            }
        }
        return result;
    }
};