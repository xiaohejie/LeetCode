#include<iostream>
#include<vector>
using namespace std;
/*
	57-插入区间：
		画图
*/
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int len = intervals.size(), i = 0;
		vector<vector<int>> ans;
		//如果两个区间没有交集
 		while (i < len && intervals[i][1] < newInterval[0]) {
			ans.push_back(intervals[i]);
			i++;
		}
		//如果有交集并且还没有到最后
		if (i < len)
		{
			newInterval[0] = min(intervals[i][0], newInterval[0]);
			while (i < len && intervals[i][0] <= newInterval[1]) {		//这里得注意一下，intervals[i][0] <= newInterval[1]
				newInterval[1] = max(intervals[i++][1], newInterval[1]);
			}
		}
		ans.push_back(newInterval);
		while (i < len) {
			ans.push_back(intervals[i++]);
		}
		return ans;
		//法1：
		/*vector<vector<int>> res;
		int left = newInterval[0], right = newInterval[1];
		bool isVisited = 0;
		for (auto& interval : intervals) {
			if (interval[1] < left) {
				//在区间的右侧且没有交集
				res.push_back(interval);
			}
			else if (interval[0] > right) {
				//在区间的左侧且没有交集
				if (!isVisited) {
					res.push_back({ left, right });
					isVisited = true;
				}
				res.push_back(interval);
			}
			else {
				//与插入区间有交集，计算他们的交集
				left = min(left, interval[0]);
				right = max(right, interval[1]);
			}
		}
		//如果所有元素都已遍历，还是没有插入
		if (!isVisited) {
			res.push_back({ left, right });
		}
		return res;*/
	}
};