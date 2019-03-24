/*
Teemo Attacking https://leetcode.com/problems/teemo-attacking/description/

思路和合并区间那道题一样，忘了是哪题了，主要需要注意怎么简化代码
*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0) return 0;
        int pos1 = timeSeries[0];
        int pos2 = timeSeries[0];
        int result = 0;
        for(int i=1; i<timeSeries.size(); i++){
            if(timeSeries[i]>timeSeries[i-1]+duration){
                result = result + pos2 - pos1 + duration;
                pos1 = timeSeries[i];
                pos2 = timeSeries[i];
            }else{
                pos2 = timeSeries[i];
            }
        }
        return result + pos2 - pos1 + duration;
    }
};