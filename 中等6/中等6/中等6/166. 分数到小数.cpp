#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
/*
	166. 分数到小数
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        //转换成长整型进行计算
        long long x = numerator, y = denominator;
        if (x % y == 0) {
            //说明可以整除
            return to_string(x / y);
        }

        //判断正负
        if ((x < 0) ^ (y < 0)) {
            ans += '-';
        }
        x = abs(x), y = abs(y);
        ans += to_string(x / y) + ".";
        x %= y;
        unordered_map<long long, int> pos;
        while (x) {
            //记录如果是循环数的位置，需要在哪里进行插入括号
            pos[x] = ans.length();
            x *= 10;
            ans += to_string(x / y);
            x %= y;
            if (pos.count(x)) {
                //如果x已经出现，说明是循环小数
                //进行插入括号
                ans.insert(pos[x], "(");
                ans += ")";
                break;
            }
        }
        return ans;
    }
};