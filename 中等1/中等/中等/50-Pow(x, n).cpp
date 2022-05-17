#include<iostream>
using namespace std;
/*
	Pow(x, n):
		利用折半法
		然后还需要判断n的奇偶性
*/
class Solution {
public:
	double helper(double x, long long n) {
		//递归结束条件
		if (n == 0) {
			return 1.0;
		}
		//利用折半法，res = y * y
		double y = helper(x, n / 2);
		//判断 n的奇偶性，奇数的话还需要再*x
		return n % 2 == 0 ? y * y : y * y * x;
	}
	double myPow(double x, int n) {
		long long N = n;
		return N > 0 ? helper(x, N) : 1.0 / helper(x, N);
		/*会超出时间限制
		double res = 1;
		if (n == 0) {
			return 1.0;
		}
		else if (n < 0) {
			x = 1.0 / x;
			n = -n;
		}
		for (int i = 0; i < n; i++) {
			res *= x;
		}
		return res;
		*/
	}
};