#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*
	1760. ������������Ŀ����
    ʹ�ö��ֲ��ҷ�
*/
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int i, m, l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) / 2;      //�ҵ��м�ֵ���ж���Ҫ���ٴ�
            for (i = m = 0; i < nums.size(); i++) {
                m += (nums[i] - 1) / mid;       //������Ҫ���ٴ�
            }
            //ʹ�ö��ַ�  
            if (m <= maxOperations) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
};