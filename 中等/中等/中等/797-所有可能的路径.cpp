#include<iostream>
#include<vector>
using namespace std;
/*
	���п��ܵ�·����
		ʹ�û��ݷ�
*/
class Solution {
public:
	vector<int> ans;
	vector<vector<int>> res;
	void backtrack(vector<vector<int>>& graph, int start) {
		ans.push_back(start);
		if (start == graph.size() - 1) {
			//�����������һ���㣬�Ϳ��ԷŽ�res
			res.push_back(ans);
		}
		for (auto g : graph[start]) {
			//�Ե�i������Ե������������л���
			backtrack(graph, g);
		}
		ans.pop_back();		//���ݣ�ȥ�����һ��Ԫ��
		return;
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int len = graph.size();
		backtrack(graph, 0);
		return res;
	}
};