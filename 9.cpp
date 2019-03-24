/*
9. Palindrome Number https://leetcode.com/problems/palindrome-number/description/

优化方法、倒置整个数或是只倒置一半
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};

bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        int y = x,z=0;
        
        while(y){
            z*=10;
            z+=(y%10);
            y=y/10;
        }
        
        if(x==z)
            return true;
        
        return false;
    }
