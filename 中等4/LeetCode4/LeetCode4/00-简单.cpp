#include<iostream>
using namespace std;
/*
	1175. 质数排列
        将所有质数的排列和所有合数的排列进行相乘
*/
class Solution {
    int mod = 1e9 + 7;
public:
    //判断是否是质数
    bool isZhishu(int n) {
        if (n == 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        for (int i = 2; i < n / 2; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        int isCount = 0, noCount = 0;
        //得到质数和合数的个数
        for (int i = 1; i <= n; i++) {
            if (isZhishu(i)) {
                isCount++;
            }
            else {
                noCount++;
            }
        }
        //计算排列组合
        int isSum = 1, noSum = 1;
        for (int i = isCount; i > 1; i--) {
            isSum *= i;
            isSum %= mod;
        }
        for (int i = noSum; i > 1; i--) {
            noSum *= i;
            noSum %= mod;
        }
        return (isSum * noSum) % mod;
    }
};