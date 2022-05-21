#include<iostream>
#include<vector>
using namespace std;
/*
	��ͬ·��III���뵺�������ƣ�����һ�𿴣���
		ʹ�û��ݷ�
*/
class Solution {
public:
	int m = 0, n = 0;
	int res = 0;
	void dfs(int i, int j, int emptySquares, vector<vector<int>>& grid) {
		/*��ֹ�������������������õ�Ϊ�ϰ��㡢�õ��Ѿ��߹���*/
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1 || grid[i][j] == -2) {
			return;
		}
		/*�Ѿ����������*/
		if (grid[i][j] == 2) {
			/*�Ѿ��ĵ�������㣬�������еĿյ��Ѿ��߹�*/
			if (emptySquares == -1) {
				res++;
			}
			return;
		}
		/*����Ļ������Ǹ��¸õ㣬���������ҽ��б���*/
		grid[i][j] = -2;
		dfs(i+1, j, emptySquares-1, grid);
		dfs(i-1, j, emptySquares-1, grid);
		dfs(i, j+1, emptySquares-1, grid);
		dfs(i, j-1, emptySquares-1, grid);

		/*���л���*/
		grid[i][j] = 0;
		//���ݵ�ʱ��emptySquares����Ҫ���иı䣨�������Ҫ���Ҳ�̫����
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		m = grid.size();		//����
		n = grid[0].size();		//����
		int emptySquares = 0;	//�յĵ���
		/*���ҿյĵ���*/
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					emptySquares++;
				}
			}
		}
		/*������㣬��ʼdfs*/
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					//��ʼ��
					dfs(i, j, emptySquares, grid);
				}
			}
		}
		return res;
	}
};