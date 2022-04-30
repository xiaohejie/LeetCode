#include<iostream>
#include<vector>
using namespace std;
/*
	��������������̫ƽ�������ˮ���������ƣ�
		�ӵ�һ�����ʿ�ʼ���������������߲��У������ת�䣨�ϣ��£�����
*/
class Solution {
private:
	int m = 0;
	int n = 0;
	vector<pair<int, int>> directions{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
public:
	bool helper(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int i, int j, int index) {//index��ʾ�������ڼ�����
		if (board[i][j] != word[index]) {
			return false;		//�����ǰ�����ȣ��򷵻�false
		}
		else if (index == word.length() - 1) {
			return true;		//������������һ�����ʣ�������ȣ�˵���Ѿ��ҵ�
		}
		//��������ȣ���û�е������һ���ַ�
		visited[i][j] = true;		//��¼��ǰλ���Ѿ����ʹ�
		bool result = false;		//��¼�Ƿ���ڸõ���
		//�������ҽ��б���������Ҫ��û�з��ʹ��ĵ���
		for (auto& dir : directions) {
			int newI = i + dir.first, newJ = j + dir.second;
			//�ж�δ�����߽�
			if (newI >= 0 && newI < m && newJ >= 0 && newJ < n) {
				//���Ҹõ���û�з��ʹ�
				if (visited[newI][newJ] == false) {
					bool flag = helper(board, visited, word, newI, newJ, index + 1);
					if (flag) {
						return true;
					}
				}
			}
		}
		//�жϵ����Ҫ�����ַ�����Ϊδ���ʹ�
		visited[i][j] = false;
		return result;
	}
    bool exist(vector<vector<char>>& board, string word) {
		m = board.size();
		n = board[0].size();
		vector<vector<int>> visited(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				bool flag = helper(board, visited, word, i, j, 0);
				if (flag) {
					return true;
				}
			}
		}
		return false;
    }
};