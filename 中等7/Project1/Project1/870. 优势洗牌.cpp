#include<iostream>
#include<vector>
#include <numeric>      // std::iota
#include<algorithm>
using namespace std;
/*
	870. 优势洗牌
*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        //idx[0]对应nums中最小元素的下标
        //这里的排序是根据nums中的数字大小进行排序的
        sort(idx1.begin(), idx1.end(), [&](int i, int j) {return nums1[i] < nums1[j]; });
        sort(idx2.begin(), idx2.end(), [&](int i, int j) {return nums2[i] < nums2[j]; });

        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++) {
            //如果nums1中的最小元素大于nums2中的最小元素
            if (nums1[idx1[i]] > nums2[idx2[left]]) {
                //就将ans中nums2最小元素的下标替换成nums1中最小元素的下标
                ans[idx2[left]] = nums1[idx1[i]];
                ++left;
            }
            else {
                //否则的话，就让nums1的最小元素去对nums2的最大元素
                ans[idx2[right]] = nums1[idx1[i]];
                --right;
            }
        }
        return ans;
    }
};