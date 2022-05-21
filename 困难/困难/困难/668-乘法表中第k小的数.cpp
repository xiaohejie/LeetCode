#include<iostream>
using namespace std;
/*
	乘法表中第k小的数（与378题有序矩阵中第 K 小的元素类似）：
		使用二分法查找
*/
class Solution {
public:
	//用于计算比中位数小的有多少个数字
	int count(int m, int n, int mid) {
		int i = m, j = 1;
		int count = 0;
		while (i >= 1 && j <= n) {
			if (i * j <= mid) {
				count += i;
				j++;
			}
			else {
				i--;
			}
		}
		return count;
	}
	int findKthNumber(int m, int n, int k) {
		int left = 1, right = m * n;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (count(m, n , mid) < k) {
				//如果比当前中位数小的个数小于k，则说明第k小的数字还在中位数后面，中位数就要往上加
				left = mid + 1;
			}
			else {
				//反之就说明，第k小的数字在中位数后前面，中位数就要减
				right = mid;
			}
		}
		return left;
	}
};