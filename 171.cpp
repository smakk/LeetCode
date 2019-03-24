/*
 Excel Sheet Column Number https://leetcode.com/problems/excel-sheet-column-number/description/
*/

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
    int times = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        result = result + (s[i] - 'A' + 1)*pow(26, times++);
    }
    return result;
    }
};