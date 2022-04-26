#pragma once
#include<iostream>
#include <vector>
using namespace std;

int merge(vector<int>& nums, int l, int r) {
    //递归过程中，如果L  R的范围缩减到1，那么肯定没有逆序对，直接返回
    if (l >= r) return 0;

    int mid = (l + r) >> 1;
    //将当前数组分成两个更小的数组
    int res = merge(nums, l, mid) + merge(nums, mid + 1, r);

    vector<int> temp;
    int i = l, j = mid + 1;
    //比较左边数组和右边数组当前最前面的数值的大小
    while (i <= mid && j <= r)
        //如果是左边数组大小小于等于右边数组当前数值，那么就不存在逆序对
        if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
        else {
            //如果左边当前元素的数值大于右边数组当前元素的数值
            //那么存在逆序对数量是mid-i+1
            temp.push_back(nums[j++]);
            res += mid - i + 1;
        }
    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= r) temp.push_back(nums[j++]);

    //并
    int k = l;
    for (auto x : temp) nums[k++] = x;

    return res;
}

int inversePairs(vector<int>& nums) {
    return merge(nums, 0, nums.size() - 1);
}
