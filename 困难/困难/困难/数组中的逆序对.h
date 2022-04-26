#pragma once
#include<iostream>
#include <vector>
using namespace std;

int merge(vector<int>& nums, int l, int r) {
    //�ݹ�����У����L  R�ķ�Χ������1����ô�϶�û������ԣ�ֱ�ӷ���
    if (l >= r) return 0;

    int mid = (l + r) >> 1;
    //����ǰ����ֳ�������С������
    int res = merge(nums, l, mid) + merge(nums, mid + 1, r);

    vector<int> temp;
    int i = l, j = mid + 1;
    //�Ƚ����������ұ����鵱ǰ��ǰ�����ֵ�Ĵ�С
    while (i <= mid && j <= r)
        //�������������СС�ڵ����ұ����鵱ǰ��ֵ����ô�Ͳ����������
        if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
        else {
            //�����ߵ�ǰԪ�ص���ֵ�����ұ����鵱ǰԪ�ص���ֵ
            //��ô���������������mid-i+1
            temp.push_back(nums[j++]);
            res += mid - i + 1;
        }
    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= r) temp.push_back(nums[j++]);

    //��
    int k = l;
    for (auto x : temp) nums[k++] = x;

    return res;
}

int inversePairs(vector<int>& nums) {
    return merge(nums, 0, nums.size() - 1);
}
