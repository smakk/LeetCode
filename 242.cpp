/*
Valid Anagram https://leetcode.com/problems/valid-anagram/description/

排序
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

//hash

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int> m;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second != 0)
                return false;
        }
        return  true;
    }
};