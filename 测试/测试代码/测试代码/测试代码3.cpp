#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution3 {
public:
	vector<vector<int>> res;
	vector<int> ans;
	vector<int> visited;
	void dfs(vector<int>& nums, int idx) {
		if (idx == nums.size()) {
			cout << "." << endl;
			res.push_back(ans);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			//剪枝操作
			if (visited[i] == 1) {		//表示当前字符已经访问过
				continue;
			}
			if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 1) {
				//去重操作
				continue;
			}

			ans.push_back(nums[i]);
			cout << nums[i] << " ";
			visited[i] = 1;
			dfs(nums, idx+1);

			//回溯
			cout << endl;
			ans.pop_back();
			visited[i] = 0;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int n = nums.size();
		visited.resize(n);
		//进行排序
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return res;
	}
};

int main3() {
	Solution3 s;
	vector<int> nums{ 1,1,2 };
	vector<vector<int>>ans = s.permuteUnique(nums);
	return 0;
}