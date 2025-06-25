// 204. 计数质数
// https://leetcode.cn/problems/count-primes/
// tags: 数学

#include "common.h"

// class Solution {
// public:
//     int countPrimes(int n) {
//         vector<bool> isPrime(n, true);
//         for (int i = 2; i < n; i++) {
//             if (isPrime[i]) {
//                 for (int j = 2*i; j < n; j+=i) {
//                     isPrime[j] = false;
//                 }
//             }
//         }
//         int count = 0;
//         for (int i = 2; i < n; i++) {
//             if (isPrime[i]) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };

//.优化
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i*i; j < n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};
