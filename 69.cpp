/*
 Sqrt(x) https://leetcode.com/problems/sqrtx/description/
*/

class Solution {
public:
    int mySqrt(int x) {
        long long pos1 = 0;
        long long pos2 = x;
        long long result = x;
        while(pos1<pos2){
            long long middle = (pos1+pos2)/2+1;
            if(middle*middle == result)
                return middle;
            else if(middle*middle < result){
                pos1 = middle;
            }else{
                pos2 = middle-1;
            }
        }
        return pos1;
    }
};