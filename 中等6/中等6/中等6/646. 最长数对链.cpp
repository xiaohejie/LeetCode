#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	646. 最长数对链（与435、无重叠区间类似）
		动态规划、贪心
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
		//使用贪心
		int cur = INT_MIN, res = 0;
		//进行排序（排序的方式和我想的有些不同，需要注意一下）
		sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
			return a[1] < b[1];
			});
		for (auto& p : pairs) {
			if (cur < p[0]) {
				cur = p[1];
				res++;
				cout << p[0] << " " << p[1] << endl;
			}
		}
		return res;
    }
};
class SolutionDP {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		//使用动态规划（不太明白）
		int n = pairs.size();
		sort(pairs.begin(), pairs.end());
		//创建动态容器
		vector<int> dp(n, 1);
		//状态转移方程
		for (int i = 0; i < n; i++) {
			//这里j这样循环的原因是，dp[j]的不是递增的，所以要从0开始遍历（dp[j]不一定小于dp[j+1]）
			for (int j = 0; j < i; j++) {
				if (pairs[j][1] < pairs[i][0]) {
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
		return dp[n - 1];
	}
};