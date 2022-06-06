#include<iostream>
#include<vector>
using namespace std;
/*
	���ʾ��룺
		�ֱ���index1��index2��¼words1��word2��λ�ã�
		�ֱ��������֮��Ĳ��
		�ҵ���Сֵ
*/
class Solution {
public:
	int findClosest(vector<string>& words, string word1, string word2) {
		int len = words.size();
		int ans = INT_MAX;
		int index1 = -1, index2 = -1;
		for (int i = 0; i < len; i++) {
			if (word1 == words[i]) {
				index1 = i;
			}
			if (word2 == words[i]) {
				index2 = i;
			}
			if (index1 >= 0&& index2 >= 0) {
				ans = min(ans, abs(index1 - index2));
			}
		}
		return ans;
	}
};