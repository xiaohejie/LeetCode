#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	����������־�ļ���
		��ͨ��find�����ҳ���һ��' '��λ��
		{
			���֮����������־���Ͳ���
			�����������ĸ��־{
				���մ���ʶ��֮�����ĸ��С��������
				��С��ͬ�ٰ��ձ�ʶ����С��������
			}
		}
*/
class Solution {
public:
	//����ĸ��־�������򣬱Ƚ������ַ���
	static bool cmp(string& log1, string& log2) {
		int index1 = log1.find(' ');
		int index2 = log2.find(' ');
		if (log1.substr(index1 + 1) != log2.substr(index2 + 1)) {
			return log1.substr(index1 + 1) < log2.substr(index2 + 1);
		}
		else {
			return log1 < log2;
		}
	}
	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> strs;		//�洢��ĸ��־
		vector<string> nums;		//�洢������־
		if (logs.size() <= 1) {
			return logs;
		}
		//�ֱ��ҳ���ĸ��־��������־
		for (int i = 0; i < logs.size(); i++) {
			int index = logs[i].find(' ');
			//ȷ����һ���ַ�
			auto n = logs[i][index + 1];
			if (n >= '0' && n <= '9') {
				//��������־�Ž�ȥ
				nums.push_back(logs[i]);
			}
			else {
				strs.push_back(logs[i]);
			}
		}
		//��������������־����Ҫ
		sort(strs.begin(), strs.end(), cmp);
		//���кϲ�
		for (int i = 0; i < nums.size(); i++) {
			strs.push_back(nums[i]);
		}

		return strs;
	}
};