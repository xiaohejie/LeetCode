#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
/*
	166. ������С��
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        //ת���ɳ����ͽ��м���
        long long x = numerator, y = denominator;
        if (x % y == 0) {
            //˵����������
            return to_string(x / y);
        }

        //�ж�����
        if ((x < 0) ^ (y < 0)) {
            ans += '-';
        }
        x = abs(x), y = abs(y);
        ans += to_string(x / y) + ".";
        x %= y;
        unordered_map<long long, int> pos;
        while (x) {
            //��¼�����ѭ������λ�ã���Ҫ��������в�������
            pos[x] = ans.length();
            x *= 10;
            ans += to_string(x / y);
            x %= y;
            if (pos.count(x)) {
                //���x�Ѿ����֣�˵����ѭ��С��
                //���в�������
                ans.insert(pos[x], "(");
                ans += ")";
                break;
            }
        }
        return ans;
    }
};