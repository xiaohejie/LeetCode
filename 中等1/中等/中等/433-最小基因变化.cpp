#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	最小基因变化：
		DFS+回溯法进行求解
*/
class Solution {
private:
	int minNum = INT_MAX, num = 0;
	unordered_set<string> set;
public:
	int minMutation(string start, string end, vector<string>& bank) {
		//递归中止条件，计算最小变化次数
		if (start == end) {
			minNum = min(minNum, num);
			return minNum;
		}
		for (auto& str: bank) {
			int diff = 0;		//判断与str有几个不同
			for (int i = 0; i < str.size(); i++) {
				if (start[i] != str[i]) {
					diff++;
				}
			}
			//比较是否只相差一个字母，并且用set进行去重操作
			if (diff == 1 && set.find(str) == set.end()) {
				//进行回溯
				set.insert(str);
				num += 1;
				minMutation(str, end, bank);
				num -= 1;		//回溯结束，次数减一
				set.erase(str);	//回溯结束，删除该字符串
			}
		}
		//如果minNum = INT_MAX，说明bank中没有只相差一个单词的，所以返回-1
		return minNum == INT_MAX ? -1 : minNum;
	}
};