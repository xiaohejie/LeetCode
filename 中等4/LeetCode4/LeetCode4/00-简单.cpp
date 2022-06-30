#include<iostream>
using namespace std;
/*
	1175. ��������
        ���������������к����к��������н������
*/
class Solution {
    int mod = 1e9 + 7;
public:
    //�ж��Ƿ�������
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
        //�õ������ͺ����ĸ���
        for (int i = 1; i <= n; i++) {
            if (isZhishu(i)) {
                isCount++;
            }
            else {
                noCount++;
            }
        }
        //�����������
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