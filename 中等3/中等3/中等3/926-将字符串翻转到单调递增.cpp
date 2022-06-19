#include<iostream>
using namespace std;
/*
	926-���ַ�����ת����������
        ʹ�ö�̬�滮
*/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;       //���ʼֵ����ʾ��i��λ��Ϊ0��1����С��ת����
        for (auto& ch : s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (ch == '1') {
                dp0New++;
            }
            else {
                dp1New++;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};