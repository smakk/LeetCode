/*
Permutation Sequence https://leetcode.com/problems/permutation-sequence/description/
*/

class Solution {
public:
    int getn(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i)
        result = result * i;
    return result;
}
string getPermutation(int n, int k) {
    --k;
    map<int, int> m = { {1,1},{2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1} };
    string result = "";
    for (int i = 1; i <= n; ++i) {
        int pos;
        //除的方式到最后两项就不成立了,当剩余两项的时候，直接赋值
        if (n - i > 1)
            pos = k / (getn(n - i)) + 1;
        else if (n - i == 1)
            pos = k + 1;
        else if (n - i == 0)
            pos = 1;
        int j = 0;
        //寻找第pos个数，如果遇到map中第二个数为0，则表示该数已经被用过了
        for (; j < pos; ++j) {
            if (m[j+1] == 0)
                ++pos;
        }
        result += to_string(j);
        m[j] = 0;
        if(n - i > 1)
            k = k % getn(n - i);
    }
    return result;
}
};