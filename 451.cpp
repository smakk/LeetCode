/*
Sort Characters By Frequency https://leetcode.com/problems/sort-characters-by-frequency/description/

string的排序比vector<char>的慢
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        sort(s.begin(),s.end(),[&hash](char& a, char& b){
           if(hash[a]!=hash[b]) 
               return hash[a]>hash[b];
            else
                return a<b;
        });
        return s;
    }
};

