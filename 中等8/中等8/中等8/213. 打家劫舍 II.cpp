#include<iostream>
#include<vector>
using namespace std;
/*
	213. ��ҽ��� II
        ʹ�ö�̬�滮��
            ����ӵ�һ�����ӿ�ʼ���Ͳ��ܱ������һ��
            ���Ҫ�������һ�䣬����Ҫ�ӵڶ��俪ʼ
*/
class Solution {
    int help(vector<int>& nums, int start, int end) {
        //������̬����
        vector<int> vec(end - start + 1);
        //��ʼ����̬����
        vec[0] = nums[start];
        vec[1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            vec[i - start] = max(vec[i - start - 2] + nums[i], vec[i- start - 1]);
        }
        return vec[end - start];
    }
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return  nums[0];
        }
        else if (len == 2) {
            return max(nums[1], nums[1]);
        }
        else {
            return max(help(nums, 0, len - 2), help(nums, 1, len - 1));
        }
    }
};