#include<iostream>
#include<vector>
using namespace std;
/*
	162. Ѱ�ҷ�ֵ
        Ҫ��ʹ��ʱ�临�Ӷ�O(logn)
        ���ַ������ǵ�nums[-1] = nums[n] = �����
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};