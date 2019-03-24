/*
Repeated DNA Sequences https://leetcode.com/problems/repeated-dna-sequences/description/

这题使用string作为索引还是太复杂了，可以用两个位来表示一个核苷酸，则使用一个int就可以保存一个DNA序列，比较次数可以缩减很多
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
    map<string,int> temp;
    int pos = 0;
    while (pos+10 <= s.size()) {
        string s_temp = s.substr(pos++,10);
        temp[s_temp]++;
        if (temp[s_temp] == 2)
            result.emplace_back(s_temp);
    }
    return result;
    }
};