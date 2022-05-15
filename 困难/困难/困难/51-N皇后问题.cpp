#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	N�ʺ����⣺�����ݷ���⣩
		
*/
class Solution {
public:
	vector<vector<string>> res;				//��
	void generateResult(vector<vector<bool>>& board) {
		vector<string> rs;
		for (int i = 0; i < board.size(); i++) {
			string ans = "";
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j]) {
					ans += 'Q';
				}
				else {
					ans += '.';
				}
			}
			rs.push_back(ans);
		}
		res.push_back(rs);
	}
	void dfs(int i, int n, vector<vector<bool>>& board, unordered_set<int>& col, unordered_set<int>& pie, unordered_set<int>& na) {
		//������ֹ������i==n��ʾ�Ѿ�����ĩβ��
		if (i == n) {
			generateResult(board);		//��¼��
			return;
		}
		//������
		for (int j = 0; j < n; j++) {
			if (col.count(j) || pie.count(i+j) || na.count(i-j)) {
				//�ж���Щ�ط�������ȡ
				continue;
			}
			board[i][j] = true;		//��¼��ǰboard[i][j]��ѡ��
			//������Щ�㲻��ȡ
			col.insert(j);
			pie.insert(i + j);
			na.insert(i - j);

			//��ת����һ��
			dfs(i + 1, n, board, col, pie, na);

			//���л��ݣ�������ǰѡȡ�ĵ㣩
			board[i][j] = false;
			col.erase(j);
			pie.erase(i + j);
			na.erase(i - j);
		}
	}

	vector<vector<string>> solveNQueens(int n) {
		vector<vector<bool>> board(n, vector<bool>(n, 0));				//��¼ѡ�е�λ��
		unordered_set<int> col, pie, na;		//����Щλ�ò�������ѡ
		//���л���
		dfs(0, n, board, col, pie, na);		//�ӵ�0�п�ʼ��n��n�У�ѡ�е�λ�ã�����ѡ��λ�� 
		return res;
	}
};