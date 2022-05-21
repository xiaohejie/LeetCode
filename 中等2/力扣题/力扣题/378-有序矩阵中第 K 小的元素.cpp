#include<iostream>
#include<vector>
using namespace std;
/*
	有序矩阵中第 K 小的元素:
		
*/
class Solution {
public:
	//计算比当前中位数小的个数
	int count(int n, int mid, vector<vector<int>>& matrix) {
		int i = n - 1, j = 0;
		int count = 0;
		while (i >= 0 && j < n) {
			if (matrix[i][j] <= mid) {
				count += i + 1;
				j++;
			}
			else {
				i--;
			}
		}
		return count;
	}
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix[0].size();
		int left = matrix[0][0], right = matrix[n - 1][n - 1];
		while (left < right) {
			int mid = left + ((right - left) >> 1);
			if (count(n, mid, matrix) < k) {
				//当前中位数的个数小于k，说明答案mid后面
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return left;
	}
};