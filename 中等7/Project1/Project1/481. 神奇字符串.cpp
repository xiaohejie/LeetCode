#include<iostream>
#include<vector>
using namespace std;
/*
	481. �����ַ���
        ʹ��˫ָ��
*/
class Solution {
public:
    int magicalString(int n) {
        if (n < 4) {
            return 1;
        }
        string s(n, '0');
        s[0] = '1', s[1] = '2', s[2] = '2';
        int res = 1;
        int i = 2;
        int j = 3;
        while (j < n) {
            int size = s[i] - '0';      //�ڵ�ǰ�ַ���������Ҫ��Ӷ��ٸ��ַ�
            int num = 3 - (s[j - 1] - '0');     //����Ҫ����ӵ��ַ���ʲô
            while (size > 0 && j < n) {
                s[j] = '0' + num;
                if (num == 1) {
                    res++;
                }
                ++j;
                --size;
            }
            i++;
        }
        return res;
    }
};