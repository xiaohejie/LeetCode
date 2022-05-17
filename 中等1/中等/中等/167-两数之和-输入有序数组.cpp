#include<iostream>
#include<vector>
using namespace std;
/*
	两数之和-输入有序数组：
		
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = numbers.size();
		int i = 0, j = len - 1;
		vector<int> res;
		if (len == 2) {
			res.push_back(1);
			res.push_back(2);
			return res;
		}
		while (i < j) {
			int sum = numbers[i] + numbers[j];
			if (sum < target) {
				i++;
			}
			else if (sum > target) {
				j--;
			}
			else {
				res.push_back(i+1);
				res.push_back(j+1);
				break;
			}
		}
		return res;
	}
};