#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	矩阵置零：
		
*/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		//记录点为0的行和列
		unordered_set<int> row, col;
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0) {
					row.insert(i);
					col.insert(j);
				}
			}
		}
		//置零
		for (auto& r : row) {
			for (int j = 0; j < n; j++) {
				matrix[r][j] = 0;
			}
		}
		for (auto& c : col) {
			for (int i = 0; i < m; i++) {
				matrix[i][c] = 0;
			}
		}
	}
};