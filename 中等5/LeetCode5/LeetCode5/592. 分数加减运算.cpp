#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
	592. �����Ӽ�����
*/
class Solution {
public:
    string fractionAddition(string expression) {
        if (expression[0] != '-') {
            expression = '+' + expression;
        }
        int n = expression.length();
        cout << n << endl;
        //�ֱ������ӷ�ĸ
        long long fenzi = 0, fenmu = 1;
        int i = 0, j = 0;
        while (i < n) {
            //�ҵ��ֺţ��ͼ�����ӷ�ĸ
            if (expression[j] == '/') {
                //���ӣ�������
                string s1 = expression.substr(i, j - i);
                //��ĸ��������
                int num = j + 1, count = 0;
                while (num < n && expression[num] != '+' && expression[num] != '-') {
                    num++;
                    count++;
                }
                string s2 = expression.substr(j + 1, count);
                //cout << s1 << " " << s2 << endl;
                if (s1[0] == '-') {
                    fenzi = fenzi * stoi(s2) - fenmu * stoi(s1.substr(1));
                }
                else {
                    //cout << "S1:" << s1 << endl;
                    fenzi = fenzi * stoi(s2) + fenmu * stoi(s1.substr(1));
                }
                fenmu = fenmu * stoi(s2);
                //cout << fenzi << " " << fenmu << endl;
                i = j + count + 1;
                cout << i << endl;
            }
            j++;
        }
        //cout << fenzi << " " << fenmu << endl;
        if (fenzi == 0) {
            return "0/1";
        }
        //�ҳ����ӷ�ĸ���������
        long long num = gcd(abs(fenzi), fenmu);
        return to_string(fenzi / num) + "/" + to_string(fenmu / num);
    }
};