#include<iostream>
#include<vector>
#include <random>
using namespace std;
/*
	497. 非重叠矩形中的随机点
*/
class Solution {
    vector<int> arr;
    vector<vector<int>>& rects;
public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        this->arr.push_back(0);
        //得到每个矩形中有多少个点，分别是从几到几
        for (auto& rect : rects) {
            this->arr.push_back(arr.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        }
    }

    vector<int> pick() {
        //生成随机矩阵的位置，从0到arr.back() - 1；
        int k = rand() % arr.back() + 1;
        int left = 0, right = rects.size();
        //使用二分法，找到矩阵在rects中的位置
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= k) right = mid;
            else left = mid + 1;
        }
        //随机找到矩阵后，在随机生成矩阵中的点
        vector<int> target = rects[right - 1];
        int x = target[2] - target[0] + 1;
        int y = target[3] - target[1] + 1;
        return { rand() % x + target[0], rand() % y + target[1] };
    }
};