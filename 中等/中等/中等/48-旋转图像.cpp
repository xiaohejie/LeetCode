#include<iostream>
#include<vector>
using namespace std;
/*
	旋转图像：
		在原图像上进行操作
		思路：画图，找规律
*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int m = matrix.size();
		for (int i = 0; i < m / 2; i++) {
			for (int j = 0; j < (m + 1) / 2; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[m - j - 1][i];
				matrix[m - j - 1][i] = matrix[m - i - 1][m - j - 1];
				matrix[m - i - 1][m - j - 1] = matrix[j][m - i - 1];
				matrix[j][m - i - 1] = temp;
			}
		}
	}
};