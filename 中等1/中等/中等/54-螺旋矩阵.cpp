#include<iostream>
#include<vector>
using namespace std;
/*
	��������
		���з������飨���£� �ң��ϣ�
		�������飨�ж��Ƿ��Ѿ����ʹ���
		���㵱ǰ������һ���ж��ٸ�Ԫ�أ�������countʱ����˵���Ѿ���ɣ�
		for(int i = 0; i <count; i++){
			res.push_back(num[i]);		
			visited[col][row] = true;
			//�ж���һ���㣬�Ƿ����
			if(<0 || >= cols || <0 || >= rows || isVisited){
				//��������Ҫ�ƶ�����һ������
				dirIdx = (dirIdx + 1) % 4;
			}
			//��ʽ���µ�ǰ��
		}
*/
class Solution {
public:
	int directions[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };		//�����������£��ң���
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return res;
		}
		int rows = matrix.size(), cols = matrix[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols, 0));		//��¼�Ƿ��Ѿ����ʹ��õ�
		int numCount = rows * cols;		//�õ�һ���ж��ٸ�����
		int row = 0, col = 0;
		int dirIdx = 0;					//��¼��ǰλ��,��ʼֵ������
		for (int i = 0; i < numCount; i++) {
			res.push_back(matrix[row][col]);
			visited[row][col] = 1;		//��¼�Ѿ����ʹ�
			//�ж���һ���㣬�Ƿ��������
			int newRow = row + directions[dirIdx][0], newCol = col + directions[dirIdx][1];
			if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || visited[newRow][newCol]) {
				//�����Ƿ������Χ���Ƿ��Ѿ����ʹ�
				//������ʹ�����Ҫ����dirInx
				dirIdx = (dirIdx + 1) % 4;		//%4��Ҫ�ǵ�4��ʱ����ʵ��0
			}
			//��ʽ���µ�ǰ��
			row += directions[dirIdx][0];
			col += directions[dirIdx][1];
		}
		return res;
	}
};
