#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	��С����仯��
		DFS+���ݷ��������
*/
class Solution {
private:
	int minNum = INT_MAX, num = 0;
	unordered_set<string> set;
public:
	int minMutation(string start, string end, vector<string>& bank) {
		//�ݹ���ֹ������������С�仯����
		if (start == end) {
			minNum = min(minNum, num);
			return minNum;
		}
		for (auto& str: bank) {
			int diff = 0;		//�ж���str�м�����ͬ
			for (int i = 0; i < str.size(); i++) {
				if (start[i] != str[i]) {
					diff++;
				}
			}
			//�Ƚ��Ƿ�ֻ���һ����ĸ��������set����ȥ�ز���
			if (diff == 1 && set.find(str) == set.end()) {
				//���л���
				set.insert(str);
				num += 1;
				minMutation(str, end, bank);
				num -= 1;		//���ݽ�����������һ
				set.erase(str);	//���ݽ�����ɾ�����ַ���
			}
		}
		//���minNum = INT_MAX��˵��bank��û��ֻ���һ�����ʵģ����Է���-1
		return minNum == INT_MAX ? -1 : minNum;
	}
};