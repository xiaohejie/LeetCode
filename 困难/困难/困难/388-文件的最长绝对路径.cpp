#include<iostream>
#include <vector>
using namespace std;
/*
	388-�ļ��������·����
		��ջģ��DFS�Ĺ��̣�
			�����ǰ�ַ��������ַ�{
				���ﻹ��Ҫ�ж�cnt(\t�ĸ���)�Ƿ�С��v.size(){
					С�ڵĻ�Ҫ���г�ջ
				}

				����temp��
				���ж��Ƿ����ļ����Ƿ��С�.����
			}else if(��ǰ�ַ���'\n'){
			
			}else if(��ǰ�ַ��ǡ�\t��){
			
			}

*/
class Solution {
public:
	int lengthLongestPath(string input) {
		input += '\n';		//������\n��Ϊֻ�������\n�ŻὫ����ļ��ӽ�ȥ
		vector<string> v;
		string temp = "";	//�������ַ������ļ�����Ŀ¼����
		bool isFile = false;
		int ans = 0;
		int curLen = 0;		//��ǰ�ļ����ļ��еĳ���
		int cnt = 0;		//���ڴ�\t������
		for (int i = 0; i < input.size(); i++) {
			//�жϵ�ǰ�ַ���ʲô
			if (isalpha(input[i]) || input[i] == '.' || isdigit(input[i] || input[i] == ' ')) {
				while (cnt < v.size()) {
					//����㲻������ͼ��⣬�����˺��滹����0��
					curLen -= v.back().size();
					v.pop_back();
				}

				temp += input[i];
				if (input[i] == '.') {
					//������ǰ��һ���ļ�
					isFile = true;
				}
			}
			else if (input[i] == '\n') {
				//��ʾ�ѷ��ʵ���ǰ�ļ����ļ��еĽ�β�����Է���ջ��
				v.push_back(temp);
				curLen += temp.size();		//����Ŀǰ�ĳ���
				if (isFile) {
					//������ļ�����Ҫ�������ֵ�ж�
					int size = v.size() - 1;		//��Ϊ����·��ÿ���ļ�������/
					ans = max(ans, curLen + size);
				}
				//�ж����֮����Ҫ���и���
				isFile = false;
				temp = "";
				cnt = 0;		//����㲻��
			}
			else if (input[i] == '\t') {
				//����\t������
				cnt++;

			}
		}
		return ans;
	}
};