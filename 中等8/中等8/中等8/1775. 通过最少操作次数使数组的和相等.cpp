#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
	1775. 通过最少操作次数使数组的和相等
*/
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        //提前判断
        if (6 * nums1.size() < nums2.size() || nums1.size() > 6 * nums2.size()) {
            return -1;
        }
        int d = accumulate(nums2.begin(), nums2.end(), 0) - accumulate(nums1.begin(), nums1.end(), 0);      //得到差值
        if (d < 0) {
            d = -d;
            swap(nums1, nums2);     //数组交换
        }
        int cnt[6]{};       //统计每个数的最大变化量
        for (int x : nums1) {
            ++cnt[6 - x];   //nums1变成6
        }
        for (int x : nums2) {
            ++cnt[x - 1];   //nums2变成1
        }
        for (int i = 5, ans = 0;;--i) {     //从大到小枚举最大变化量 5 4 3 2 1
            if (i * cnt[i] >= d) {      //可以让d变为0
                return ans + (d + i - 1) / i;       //直接返回原先的ans加上最后需要让d变为0所需要的次数
            }
            ans += cnt[i];      //需要所有最大变化量为i的数
            d -= i * cnt[i];
        }
    }
};