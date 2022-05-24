#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //先对intervals进行排序
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();) {
            int t = intervals[i][1];     //区间的右值
            //下一个区间
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t)         //j区间的左值小于i区间的右值（说明两者有交集）
            {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], t });
            i = j;              //i = j，观察下一个没有交集的点
        }
        return ans;
    }
};