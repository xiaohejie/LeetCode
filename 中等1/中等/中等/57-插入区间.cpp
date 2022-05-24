#include<iostream>
#include<vector>
using namespace std;
/*
	57-�������䣺
		��ͼ
*/
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int len = intervals.size(), i = 0;
		vector<vector<int>> ans;
		//�����������û�н���
 		while (i < len && intervals[i][1] < newInterval[0]) {
			ans.push_back(intervals[i]);
			i++;
		}
		//����н������һ�û�е����
		if (i < len)
		{
			newInterval[0] = min(intervals[i][0], newInterval[0]);
			while (i < len && intervals[i][0] <= newInterval[1]) {		//�����ע��һ�£�intervals[i][0] <= newInterval[1]
				newInterval[1] = max(intervals[i++][1], newInterval[1]);
			}
		}
		ans.push_back(newInterval);
		while (i < len) {
			ans.push_back(intervals[i++]);
		}
		return ans;
		//��1��
		/*vector<vector<int>> res;
		int left = newInterval[0], right = newInterval[1];
		bool isVisited = 0;
		for (auto& interval : intervals) {
			if (interval[1] < left) {
				//��������Ҳ���û�н���
				res.push_back(interval);
			}
			else if (interval[0] > right) {
				//������������û�н���
				if (!isVisited) {
					res.push_back({ left, right });
					isVisited = true;
				}
				res.push_back(interval);
			}
			else {
				//����������н������������ǵĽ���
				left = min(left, interval[0]);
				right = max(right, interval[1]);
			}
		}
		//�������Ԫ�ض��ѱ���������û�в���
		if (!isVisited) {
			res.push_back({ left, right });
		}
		return res;*/
	}
};