#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	462. �����ƶ�����ʹ����Ԫ����� II:
		�����ǵ���λ��
*/
class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int count = 0;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int midNum = nums[len / 2];
		for (int i = 0; i < nums.size(); i++) {
			count += abs(nums[i] - midNum);
		}	
		return count;
	}
};