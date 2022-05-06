#include<iostream>
#include<vector>
using namespace std;
/*
	递增子序列：
		通过回溯法进行求解：
		（1）去重（重要）
		（2）长度大于2才可以放入res中
		（3）必须是非递减
*/
class Solution {
public:
	//判断重复字符串
	bool isFirst(vector<int>& nums, int last, int pos) {
		for (int i = last + 1; i < pos; i++) {
			if (nums[i] == nums[pos]) {//从已经存入ans中的最后一个数字的后一个数字开始，发哦pos的前一个，如果有和pos相等的数字，该数字就不可取
				return false;
			}
		}
		return true;
	}
	void dfs(vector<int>& nums, int last, int pos, vector<int>& ans, vector<vector<int>>& res) {
		//last：表示当前ans中的元素；pos：表示当前需要进行判断的数字
		if (nums.size() == pos) {
			//已到达末尾，可以直接返回
			return;
		}
		//检查nums[pos]是否符合要求：增加empty是为了ans为空
		if ((ans.empty() || nums[pos] >= ans.back()) && isFirst(nums, last, pos)) {
			ans.push_back(nums[pos]);
			//判断是否超过两个元素
			if (ans.size() >= 2) {
				res.push_back(ans);
			}
			dfs(nums, pos, pos + 1, ans, res);	//继续处理下一个
			ans.pop_back();				//把当前放入的吐出来
		}
		dfs(nums, last, pos + 1, ans, res);
	}
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> ans;
		dfs(nums, -1, 0, ans, res);
		return res;
	}
};