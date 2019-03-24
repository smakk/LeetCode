/*
Count Primes https://leetcode.com/problems/count-primes/description/

记住直接判断一个是不是质数的方法，不能平方，会溢出
*/
class Solution {
public:
    int countPrimes(int n) {
        bool* isPrime = new bool[n];
        for(int i = 2; i < n; i++){
            isPrime[i] = true;
        }
        for(int i = 2; i*i < n; i++){
            if (!isPrime[i])
                continue;
            for(int j = i * i; j < n; j += i){
                isPrime[j] = false;
            }
        }
        int count = 0;
   for (int i = 2; i < n; i++) {
      if (isPrime[i]) count++;
   }
   return count;
    }
};


class Solution {
public:
    
    bool is_prime(int n){
        if(n<=1) return false;
        int sqr=sqrt(n);
        for(int i=2;i<=sqr;i++)
            if(n%i==0)
                return false;
        return true;
    }
    
    int countPrimes(int n) {
        int result = 0;
        for(int i=1;i<n;i++){
            if(is_prime(i))
                result++;
        }
        return result;
    }
};