/*
 Find the Difference https://leetcode.com/problems/find-the-difference/description/
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> hash;
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            hash[s[i]]--;
        }
        for(auto i=hash.begin();i!=hash.end();i++){
            if(i->second == 1)
                return i->first;
        }
        return 'A';
    }
};

