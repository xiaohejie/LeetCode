#include<iostream>
#include<vector>
using namespace std;
/*
	4. Ѱ�����������������λ��
        ע�⣺ʱ�临�Ӷ�O(log(m+n))����ʹ�ö��ֲ���
*/
//ʹ�ö��ֲ��ҷ�
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2 == 0) {
            int left = find(nums1, 0, nums2, 0, n / 2);             //�е㲻��Ϊʲô��n / 2�� n / 2 + 1
            int right = find(nums1, 0, nums2, 0, n / 2 + 1);
            return (left + right) / 2.0;
        }
        else {
            return find(nums1, 0, nums2, 0, n / 2 + 1);
        }
    }
    //�ҳ��������е�k���Ԫ�أ��ֱ���±�i��j��ʼ��
    int find(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        //��֤nums1�ĳ��Ȳ�����nums2�ĳ���(���±꿪ʼ)
        if (nums1.size() - i > nums2.size() - j) {
            return find(nums2, j, nums1, i, k);
        }
        //���nums1��û����Ԫ�أ��ͷ���nums2�ĵ�k��Ԫ��
        if (nums1.size() == i) {
            return nums2[j + k - 1];
        }
        //�ݹ���ֹ����
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        /*�۰���ҵĹ���*/
        //�ҳ��������k / 2�±꣨���±�i��j��ʼ��
        int idx1 = min((int)nums1.size(), i + k / 2);   //����i + k / 2���ܻ����nums1.size()
        int idx2 = j + k - k / 2;       //�����ʹ�ü�����û�㶮��
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


//��ͨ����
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