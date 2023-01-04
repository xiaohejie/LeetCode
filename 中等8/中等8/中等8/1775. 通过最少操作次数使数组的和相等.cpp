#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
	1775. ͨ�����ٲ�������ʹ����ĺ����
*/
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        //��ǰ�ж�
        if (6 * nums1.size() < nums2.size() || nums1.size() > 6 * nums2.size()) {
            return -1;
        }
        int d = accumulate(nums2.begin(), nums2.end(), 0) - accumulate(nums1.begin(), nums1.end(), 0);      //�õ���ֵ
        if (d < 0) {
            d = -d;
            swap(nums1, nums2);     //���齻��
        }
        int cnt[6]{};       //ͳ��ÿ���������仯��
        for (int x : nums1) {
            ++cnt[6 - x];   //nums1���6
        }
        for (int x : nums2) {
            ++cnt[x - 1];   //nums2���1
        }
        for (int i = 5, ans = 0;;--i) {     //�Ӵ�Сö�����仯�� 5 4 3 2 1
            if (i * cnt[i] >= d) {      //������d��Ϊ0
                return ans + (d + i - 1) / i;       //ֱ�ӷ���ԭ�ȵ�ans���������Ҫ��d��Ϊ0����Ҫ�Ĵ���
            }
            ans += cnt[i];      //��Ҫ�������仯��Ϊi����
            d -= i * cnt[i];
        }
    }
};