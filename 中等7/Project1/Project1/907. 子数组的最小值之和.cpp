#include<iostream>
#include<vector>
using namespace std;
/*
	907. 子数组的最小值之和
    使用单调栈或者动态规划
*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> monoStack;
        vector<int> left(n), right(n);
        //找到左边第一个小于arr[i]的元素，left[i]为从左边开始，下标i最小值的子数组的个数（从最左边开始）
        for (int i = 0; i < n; i++) {
            while(!monoStack.empty() && arr[i] <= arr[monoStack.back()]) {
                monoStack.pop_back();
            }
            left[i] = i - (monoStack.empty() ? -1 : monoStack.back());
            monoStack.emplace_back(i);
        }
        monoStack.clear();
        //找到右边第一个大于等于arr[i]放入元素，right[i]为从左边开始，下标i最小值的子数组的个数（从最右边开始）
        for (int i = n - 1; i >= 0; i--) {
            while (!monoStack.empty() && arr[i] < arr[monoStack.back()]) {
                monoStack.pop_back();
            }
            right[i] = (monoStack.empty() ? n : monoStack.back()) - i;
            monoStack.emplace_back(i);
        }
        //计算最小值之和
        long long ans = 0;
        long long mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)left[i] * right[i] * arr[i]) % mod;
        }
        return ans;
    }
};