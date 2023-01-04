#include<iostream>
#include<vector>
using namespace std;
/*
	1764. ͨ��������һ�������������õ�һ������
*/
class Solution {
    bool check(vector<int>& group, vector<int>& nums, int k) {
        if (k + group.size() > nums.size()) {
            return false;       //���Ȳ�����ֱ�ӷ���false
        }
        for (int j = 0; j < group.size(); j++) {
            if (group[j] != nums[k + j]) {
                return false;
            }
        }
        return true;
    }
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0;
        for (int k = 0; k < nums.size() && i < groups.size();) {
            //�����k��ʼ��nums��������������Ϊgroups[i]
            if (check(groups[i], nums, k)) {
                k += groups[i].size();      //����һ�α����Ŀ�ͷ
                i++;            //��һ�α�����groups�еĳ�Ա
            }
            else {
                k++;    //û�еĻ�������nums�е���һ��Ԫ��
            }
        }
        return i == groups.size();  //����ж���û�б�������
    }
};