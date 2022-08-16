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
			//��֦����
			if (visited[i] == 1) {		//��ʾ��ǰ�ַ��Ѿ����ʹ�
				continue;
			}
			if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 1) {
				//ȥ�ز���
				continue;
			}

			ans.push_back(nums[i]);
			cout << nums[i] << " ";
			visited[i] = 1;
			dfs(nums, idx+1);

			//����
			cout << endl;
			ans.pop_back();
			visited[i] = 0;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		int n = nums.size();
		visited.resize(n);
		//��������
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