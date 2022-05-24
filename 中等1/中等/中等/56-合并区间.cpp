#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //�ȶ�intervals��������
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();) {
            int t = intervals[i][1];     //�������ֵ
            //��һ������
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t)         //j�������ֵС��i�������ֵ��˵�������н�����
            {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], t });
            i = j;              //i = j���۲���һ��û�н����ĵ�
        }
        return ans;
    }
};