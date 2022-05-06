#include<iostream>
#include<vector>
using namespace std;
/*
	��������II��
		
*/

class Solution {
public:
	int directions[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };		//���巽�����
	vector<vector<int>> generateMatrix(int n) {
		int num = n * n;
		vector<vector<bool>> visited(n, vector<bool>(n, 0));		//��¼�õ��Ƿ��Ѿ����ʹ�(���Բ���Ҫ���������Ϊ��res[i][j]��λ0ʱ����˵���Ѿ����ʹ�)
		vector<vector<int>> res(n, vector<int>(n));
		int dirIndex = 0;				//���巽��������
		int row = 0, col = 0;			//ʵʱ�����к���
		for (int i = 0; i < num; i++) {	
			res[row][col] = i + 1;
			visited[row][col] = true;
			//�ж���һ���㣬�Ƿ����
			int newRow = row + directions[dirIndex][0], newCol = col + directions[dirIndex][1];
			if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || visited[newRow][newCol]) {
				//������Ļ���Ҫ��ת����
				dirIndex = (dirIndex + 1) % 4;
			}
			//������һ����
			row += directions[dirIndex][0];
			col += directions[dirIndex][1];
		}
		return res;
	}
};