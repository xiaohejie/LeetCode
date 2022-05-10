#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	�ַ�����ˣ�������һ���ַ�����ӣ��ⷨ��̫һ������
		���ַ���ת��Ϊvector<int>�洢
		res����󳤶Ⱦ���Ϊ���߳���֮��
		��vector�����淴
*/
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int>a, b, c;
		//���ַ���ת��Ϊvector<int>�洢
		for (int i = 0; i < num1.size(); i++) {
			a.push_back(num1[i] - '0');
		}
		for (int i = 0; i < num2.size(); i++) {
			b.push_back(num2[i] - '0');
		}
		//���ý���ĳ���
		c.resize(a.size() + b.size());
		//��vector�����淴
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		//��ʼ����
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				//��һ��������Ҫ
				c[i + j] += a[i] * b[j];
				c[i + j + 1] += c[i + j] / 10;	//��λ����
				c[i + j] = c[i + j] % 10;		//ȡ��
				cout << c[i + j] << "��";
			}
		}
		//Ҫ������ж����0ȥ��
		int size = c.size() - 1;
		while (size > 0 && c[size] == 0) {
			size--;
		}
		string res = "";
		for (int i = size; i >= 0; i--) {
			// cout << c[i] << "��";
			res += '0' + c[i];
		}
		return res;
	}
};