#include<iostream>
#include<vector>
#include <numeric>      // std::iota
#include<algorithm>
using namespace std;
/*
	870. ����ϴ��
*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        //idx[0]��Ӧnums����СԪ�ص��±�
        //����������Ǹ���nums�е����ִ�С���������
        sort(idx1.begin(), idx1.end(), [&](int i, int j) {return nums1[i] < nums1[j]; });
        sort(idx2.begin(), idx2.end(), [&](int i, int j) {return nums2[i] < nums2[j]; });

        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++) {
            //���nums1�е���СԪ�ش���nums2�е���СԪ��
            if (nums1[idx1[i]] > nums2[idx2[left]]) {
                //�ͽ�ans��nums2��СԪ�ص��±��滻��nums1����СԪ�ص��±�
                ans[idx2[left]] = nums1[idx1[i]];
                ++left;
            }
            else {
                //����Ļ�������nums1����СԪ��ȥ��nums2�����Ԫ��
                ans[idx2[right]] = nums1[idx1[i]];
                --right;
            }
        }
        return ans;
    }
};