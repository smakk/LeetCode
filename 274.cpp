/*
H-Index https://leetcode.com/problems/h-index/description/
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0) return 0;
        vector<int> v(*max_element(citations.begin(),citations.end())+1,0);
        for(int i=0;i<citations.size();i++){
            v[citations[i]]++;
        }
        int last = 0;
        for(int i=v.size()-1;i>=0;i--){
            v[i] = v[i]+last;
            last = v[i];
            if(v[i]>=i)
                return i;
        }
        return 0;
    }
};