#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
	128. ���������	
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        //�Ƚ�������
        sort(nums.begin(), nums.end());
        vector<int> vec;        //�����洢ǰ��ֵ�Ĳ�
        vec.push_back(0);
        //�������飬��¼ǰ���������ֵĲ�
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                continue;
            }
            vec.push_back(nums[i] - nums[i - 1]);
        }
        int maxLength = 0;
        int len = 0;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] == 1) {
                len++;
                maxLength = max(maxLength, len);
            }
            else {
                //�������ˣ��Ƚ��бȽϣ�Ȼ��������
                maxLength = max(maxLength, len);
                len = 0;
            }
        }
        return maxLength + 1;
    }
};