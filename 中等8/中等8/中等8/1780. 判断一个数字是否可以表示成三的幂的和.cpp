#include<iostream>
#include<vector>
/*
    ת����3����
*/
using namespace std;
/*
	1780. �ж�һ�������Ƿ���Ա�ʾ�������ݵĺ�
*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> vec;
        while (n != 0) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};