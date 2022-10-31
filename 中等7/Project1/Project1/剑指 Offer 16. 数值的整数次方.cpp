#include<iostream>
using namespace std;
/*
	剑指 Offer 16. 数值的整数次方
        使用快速幂 + 递归
*/
//使用快速幂和迭代
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        int flag = n > 0 ? 1 : -1;
        long long N = abs(n);
        while (N != 0) {
            if (N & 1 == 1) {
                res = res * x;
            }
            x = x * x;
            N = N >> 1;
        }
        return flag > 0 ? res : 1 / res;
    }
};

//快速幂+递归
class Solution {
    double helper(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        //先求的N的一半
        double y = helper(x, N >> 1);
        //再判断N%2是否等于0，如果等于0返回y*y，否则返回y*y*x
        return N % 2 == 0 ? y * y : y * y * x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N > 0 ? helper(x, N) : 1.0 / helper(x, -N);
    }
};