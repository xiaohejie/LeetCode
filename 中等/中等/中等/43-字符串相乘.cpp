#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	字符串相乘：（还有一个字符串相加（解法不太一样））
		将字符串转化为vector<int>存储
		res的最大长度就设为两者长度之和
		对vector进行逆反
*/
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int>a, b, c;
		//将字符串转化为vector<int>存储
		for (int i = 0; i < num1.size(); i++) {
			a.push_back(num1[i] - '0');
		}
		for (int i = 0; i < num2.size(); i++) {
			b.push_back(num2[i] - '0');
		}
		//设置结果的长度
		c.resize(a.size() + b.size());
		//对vector进行逆反
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		//开始计算
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				//这一部分最重要
				c[i + j] += a[i] * b[j];
				c[i + j + 1] += c[i + j] / 10;	//进位操作
				c[i + j] = c[i + j] % 10;		//取余
				cout << c[i + j] << "、";
			}
		}
		//要将结果中多余的0去掉
		int size = c.size() - 1;
		while (size > 0 && c[size] == 0) {
			size--;
		}
		string res = "";
		for (int i = size; i >= 0; i--) {
			// cout << c[i] << "、";
			res += '0' + c[i];
		}
		return res;
	}
};