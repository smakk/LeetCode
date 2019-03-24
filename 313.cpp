/*
Super Ugly Number https://leetcode.com/problems/super-ugly-number/description/
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0);
    vector<int> v = { 1 };
    for (int i = 0; i<n-1; i++) {
        int mi = INT_MAX;
        for (int i = 0; i<primes.size(); i++) {
            mi = min(mi, primes[i] * v[index[i]]);
        }
        v.push_back(mi);
        for (int i = 0; i<primes.size(); i++) {
            while (primes[i] * v[index[i]]<=mi)
                index[i]++;
        }
    }
    return v.back();
    }
};