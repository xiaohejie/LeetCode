#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	重新排列日志文件：
		先通过find函数找出第一个' '的位置
		{
			如果之后是数字日志，就不懂
			否则如果是字母日志{
				按照处标识符之外的字母大小进行排序，
				大小相同再按照标识符大小进行排序
			}
		}
*/
class Solution {
public:
	//对字母日志进行排序，比较两个字符串
	static bool cmp(string& log1, string& log2) {
		int index1 = log1.find(' ');
		int index2 = log2.find(' ');
		if (log1.substr(index1 + 1) != log2.substr(index2 + 1)) {
			return log1.substr(index1 + 1) < log2.substr(index2 + 1);
		}
		else {
			return log1 < log2;
		}
	}
	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> strs;		//存储字母日志
		vector<string> nums;		//存储数字日志
		if (logs.size() <= 1) {
			return logs;
		}
		//分别找出字母日志和数字日志
		for (int i = 0; i < logs.size(); i++) {
			int index = logs[i].find(' ');
			//确定第一个字符
			auto n = logs[i][index + 1];
			if (n >= '0' && n <= '9') {
				//将整个日志放进去
				nums.push_back(logs[i]);
			}
			else {
				strs.push_back(logs[i]);
			}
		}
		//进行排序，数字日志不需要
		sort(strs.begin(), strs.end(), cmp);
		//进行合并
		for (int i = 0; i < nums.size(); i++) {
			strs.push_back(nums[i]);
		}

		return strs;
	}
};