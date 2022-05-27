#include<iostream>
#include<vector>
using namespace std;
/*
	买卖股票的最佳时机II：
		画图理解(画出该区间股票的上升和下降趋势)，就是找到每个上升区间，相加
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ans = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1]) {
				ans += (prices[i] - prices[i - 1]);
			}
		}
		return ans;
	}
};