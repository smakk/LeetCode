/*
 Longest Palindrome https://leetcode.com/problems/longest-palindrome/description/
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int result = 0;
        unordered_map<char,int> hash;
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]==1){
                hash[s[i]] = 0;
                result = result + 2;
            }else
                hash[s[i]]++;
        }
        if(s.size()>result)
            result++;
        return result;
    }
};