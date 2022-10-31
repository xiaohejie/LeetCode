#include<iostream>
using namespace std;
/*
	��ָ Offer 16. ��ֵ�������η�
        ʹ�ÿ����� + �ݹ�
*/
//ʹ�ÿ����ݺ͵���
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

//������+�ݹ�
class Solution {
    double helper(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        //�����N��һ��
        double y = helper(x, N >> 1);
        //���ж�N%2�Ƿ����0���������0����y*y�����򷵻�y*y*x
        return N % 2 == 0 ? y * y : y * y * x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N > 0 ? helper(x, N) : 1.0 / helper(x, -N);
    }
};