#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	565. ����Ƕ��
        ��������г�ʼ�������г�ʱ
*/
class Solution {
public:
    int help(vector<int>& nums, int i, vector<int>& set) {
        //���г�ʼ��
        int count = 0;
        int index = i;
        while (set[index]==0) {
            //�������±�û�б�������
            count++;
            set[index] = true;
            //����
            index = nums[index];
        }
        return count;
    }
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        vector<int> set(nums.size());       //������¼�Ѿ��������±�
        for (int i = 0; i < nums.size(); i++) {
            int count = help(nums, i, set);
            ans = max(ans, count);
        }
        return ans;
    }
};