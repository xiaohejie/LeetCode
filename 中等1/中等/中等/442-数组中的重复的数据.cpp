#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	�����е��ظ����ݣ�
		������ʹ�ö���ռ�Ļ���
			�����Ƚ�������Ȼ����һһ��Ӧ
*/
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		unordered_map<int, int>map;		//���������ֺͳ��ֵĴ���
		for (int i = 0; i < nums.size(); i++) {
			map[nums[i]]++;
			if (map[nums[i]] == 2) {
				res.push_back(nums[i]);
			}
		}
		return res;
	}
};