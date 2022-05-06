#include<iostream>
#include<vector>
using namespace std;
/*
	���������У�
		ͨ�����ݷ�������⣺
		��1��ȥ�أ���Ҫ��
		��2�����ȴ���2�ſ��Է���res��
		��3�������Ƿǵݼ�
*/
class Solution {
public:
	//�ж��ظ��ַ���
	bool isFirst(vector<int>& nums, int last, int pos) {
		for (int i = last + 1; i < pos; i++) {
			if (nums[i] == nums[pos]) {//���Ѿ�����ans�е����һ�����ֵĺ�һ�����ֿ�ʼ����Ŷpos��ǰһ��������к�pos��ȵ����֣������־Ͳ���ȡ
				return false;
			}
		}
		return true;
	}
	void dfs(vector<int>& nums, int last, int pos, vector<int>& ans, vector<vector<int>>& res) {
		//last����ʾ��ǰans�е�Ԫ�أ�pos����ʾ��ǰ��Ҫ�����жϵ�����
		if (nums.size() == pos) {
			//�ѵ���ĩβ������ֱ�ӷ���
			return;
		}
		//���nums[pos]�Ƿ����Ҫ������empty��Ϊ��ansΪ��
		if ((ans.empty() || nums[pos] >= ans.back()) && isFirst(nums, last, pos)) {
			ans.push_back(nums[pos]);
			//�ж��Ƿ񳬹�����Ԫ��
			if (ans.size() >= 2) {
				res.push_back(ans);
			}
			dfs(nums, pos, pos + 1, ans, res);	//����������һ��
			ans.pop_back();				//�ѵ�ǰ������³���
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