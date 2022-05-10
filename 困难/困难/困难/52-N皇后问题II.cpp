#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	N�ʺ�����II��
		
*/
class Solution {
public:
	int num = 0;
	void DFS(int i, int n, vector<vector<bool>>& board, unordered_set<int>& col, unordered_set<int>& pie, unordered_set<int>& na) {
		//������ֹ����
		if (i == n) {
			//Ҫ���𰸸���
			num++;
			return;
		}
		//������
		for (int j = 0; j < n; j++) {
			//���Խ�����е�����
			if (col.count(j) || pie.count(i+j) || na.count(i-j)) {
				continue;
			}
			//����
			board[i][j] = true;
			col.insert(j);
			pie.insert(i + j);
			na.insert(i-j);
			
			//����������һ��
			DFS(i+1, n, board, col, pie, na);

			//���л���
			board[i][j] = false;
			col.erase(j);
			pie.erase(i + j);
			na.erase(i-j);
		}
	
	}
	int totalNQueens(int n) {
		vector<vector<bool>> board(n, vector<bool>(n, 0));		//��¼ѡ�е�λ�ã���true��
		unordered_set<int> col, pie, na;
		DFS(0, n, board, col, pie, na);
		return num;
	}
};