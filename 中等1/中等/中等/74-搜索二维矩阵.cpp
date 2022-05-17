#include<iostream>
#include<vector>
using namespace std;
/*
	ËÑË÷¶þÎ¬¾ØÕó£º
		
*/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int i = 0;
		while (i < m) {
			if (target < matrix[i][0]) {
				return false;
			}
			else if (matrix[i][0] == target) {
				return true;
			}
			else if (matrix[i][n - 1] < target) {
				i++;
			}
			else if (matrix[i][0] < target && matrix[i][n - 1] >= target) {
				for (int j = 1; j < n; j++) {
					if (target == matrix[i][j]) {
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}
};