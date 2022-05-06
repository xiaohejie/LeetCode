#include<iostream>
using namespace std;
/*
	Pow(x, n):
		�����۰뷨
		Ȼ����Ҫ�ж�n����ż��
*/
class Solution {
public:
	double helper(double x, long long n) {
		//�ݹ��������
		if (n == 0) {
			return 1.0;
		}
		//�����۰뷨��res = y * y
		double y = helper(x, n / 2);
		//�ж� n����ż�ԣ������Ļ�����Ҫ��*x
		return n % 2 == 0 ? y * y : y * y * x;
	}
	double myPow(double x, int n) {
		long long N = n;
		return N > 0 ? helper(x, N) : 1.0 / helper(x, N);
		/*�ᳬ��ʱ������
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