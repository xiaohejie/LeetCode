#include<iostream>
#include<vector>
using namespace std;
/*
	�˻�С��K�������飺
		ʹ�û������ڣ�˫ָ�룩��
		��1��������ָ��һ��ʼ��ֱָ��0
		��2��{
				�˻��ʹӵ�0������ʼ��ˣ�
				�����left <= right && �˻���>=k��{
					�ɼ���ȥ����ָ�루prod /= nums[left]��;
					left++;
				}
				��������Ҫ���£���right - left + 1��
										�������˼�ǣ����i���˵�j����С��k�Ļ���˵�������ÿ������С��k��
		}
		��3�����ؽ��
*/
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int len = nums.size();
		int ans = 0;
		int left = 0, right = 0;
		int prod = 1;
		for (right = 0; right < len; right++) {
			prod *= nums[right];
			while (left <= right && prod >= k) {
				prod /= nums[left];
				left = left + 1;
			}
			//�������˼�ǣ����i���˵�j����С��k�Ļ���˵�������ÿ������С��k
			ans += (right - left + 1);
		}
		return ans;
	}
};