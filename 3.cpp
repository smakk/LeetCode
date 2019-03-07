/*
	两个指针前后缩进就可以了
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos1 = 0;
        int result = 0;
        int current = 0;
        map<char,int> m;
        for(int i=0;i<s.size();){
            if(m[s[i]] == 0){
                m[s[i]]++;
                current++;
                i++;
            }else{
                m[s[pos1]]--;
                pos1++;
                current--;
            }
            if(current > result)
                result = current;
        }
        return result;
    }
};