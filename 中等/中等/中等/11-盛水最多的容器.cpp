#include<iostream>
#include<vector>
using namespace std;
/*
    盛水最多的容器：
        给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
        找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
        返回容器可以储存的最大水量。

    思路：
        先从0到n - 1开始 area = min(height[0], height[n - 1]) * (n - 1 - 0 + 1)
        与ans进行max比较
        如果height[l] <= height[r]，l++;
        否则r--;
        l>=r退出循环


*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            ans = max(ans, area);
            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};
