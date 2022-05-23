#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
	寻找右区间：
		给你一个vector<vector<int>>& intervals，找到一个比[starti, endi]中endi大的startj，且这个startj在所有比他大的中index最小
*/
class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		if (intervals.size() == 1) {
			return { -1 };
		}
		vector<int> ans;
		map<int, int> map;
		int len = intervals.size();
		//保存每个区间的start的index
		for (int i = 0; i < len; i++) {
			map[intervals[i][0]] = i;
		}
		//找比每个区间end大的最小index的start
		for (int i = 0; i < len; i++) {
			auto res = lower_bound(map.begin(), map.end(), intervals[i][1]);
			if (res == map.end()) {
				ans.push_back(-1);
			}
			else {
				ans.push_back(res->second);
			}
		}
		return ans;
	}
};