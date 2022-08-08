#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
	592. 分数加减运算
*/
class Solution {
public:
    string fractionAddition(string expression) {
        if (expression[0] != '-') {
            expression = '+' + expression;
        }
        int n = expression.length();
        cout << n << endl;
        //分别计算分子分母
        long long fenzi = 0, fenmu = 1;
        int i = 0, j = 0;
        while (i < n) {
            //找到分号，就计算分子分母
            if (expression[j] == '/') {
                //分子，并更新
                string s1 = expression.substr(i, j - i);
                //分母，并更新
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
        //找出分子分母的最大公因数
        long long num = gcd(abs(fenzi), fenmu);
        return to_string(fenzi / num) + "/" + to_string(fenmu / num);
    }
};