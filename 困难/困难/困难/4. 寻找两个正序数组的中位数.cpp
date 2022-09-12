#include<iostream>
#include<vector>
using namespace std;
/*
	4. 寻找两个正序数组的中位数
        注意：时间复杂度O(log(m+n))，得使用二分查找
*/
//使用二分查找法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2 == 0) {
            int left = find(nums1, 0, nums2, 0, n / 2);             //有点不懂为什么是n / 2和 n / 2 + 1
            int right = find(nums1, 0, nums2, 0, n / 2 + 1);
            return (left + right) / 2.0;
        }
        else {
            return find(nums1, 0, nums2, 0, n / 2 + 1);
        }
    }
    //找出两数组中第k大的元素（分别从下标i和j开始）
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        //保证nums1的长度不超过nums2的长度(从下标开始)
        if (nums1.size() - i > nums2.size() - j) {
            return find(nums2, j, nums1, i, k);
        }
        //如果nums1中没有了元素，就返回nums2的第k个元素
        if (nums1.size() == i) {
            return nums2[j + k - 1];
        }
        //递归中止条件
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        /*折半查找的过程*/
        //找出两数组的k / 2下标（从下标i和j开始）
        int idx1 = min((int)nums1.size(), i + k / 2);   //这里i + k / 2可能会大于nums1.size()
        int idx2 = j + k - k / 2;       //（这边使用减法，没搞懂）
        if (nums1[idx1 - 1] < nums2[idx2 - 1]) {
            return find(nums1, idx1, nums2, j, k - (idx1 - i));
        }
        else if (nums1[idx1 - 1] > nums2[idx2 - 1]) {
            return find(nums1, i, nums2, idx2, k - (idx2 - j));
        }
        else {
            return nums1[idx1];
        }
    }
};


//普通方法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> nums;
        int i = 0, j = 0, sum = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while (i != m) {
            nums.push_back(nums1[i]);
            i++;
        }
        while (j != n) {
            nums.push_back(nums2[j]);
            j++;
        }
        if ( (m + n) % 2 != 0 ) {
            return (double)nums[(m + n) / 2];
        }
        else {
            return (double)(nums[(m + n) / 2 - 1] + nums[(m + n) / 2]) / 2;
        }
    }
};