#include<iostream>
#include<vector>
using namespace std;
/*
	ɾ�����򣺣�ɵ����Ŀ���������⣩
		��1���жϸ��ַ����ǲ��ǰ��ֵ��������������(����������ַ����������)
		��2��forѭ��{
			�õ����
		}
*/
class Solution {
public:
	int minDeletionSize(vector<string>& strs) {
		int row = strs.size();
		int col = strs[0].size();
		int count = 0;
		for (int j = 0; j < col; j++) {
			for (int i = 1; i < row; i++) {
				if (strs[i][j] < strs[i-1][j]) {
					count++;
					break;
				}
			}
		}
		return count;
	}
};