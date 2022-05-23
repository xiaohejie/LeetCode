#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
	Ѱ�������䣺
		����һ��vector<vector<int>>& intervals���ҵ�һ����[starti, endi]��endi���startj�������startj�����б��������index��С
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
		//����ÿ�������start��index
		for (int i = 0; i < len; i++) {
			map[intervals[i][0]] = i;
		}
		//�ұ�ÿ������end�����Сindex��start
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