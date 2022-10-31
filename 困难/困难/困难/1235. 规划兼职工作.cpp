#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	1235. 规划兼职工作
        使用动态规划 + 二分查找
        思路：
        不选第i个工作，那么最大报酬等于前i-1个工作的最大报酬
        选第i个工作，由于工作时间不能重叠，设j是最大的满足endTime[j] <= startTime[i]的j那么最大报酬等于前 j 个工作的最大报酬加上profit[i]
*/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        //将工作的起始时间以及薪资放在一起
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = { startTime[i], endTime[i], profit[i] };
        }
        //进行排序，按照结束时间进行排序
        sort(jobs.begin(), jobs.end(), [](const vector<int>& job1, const vector<int>& job2)-> bool {
            return job1[1] < job2[1];
            });
        vector<int> dp(n+1);
        for (int i = 1; i <= n; i++) {
            //找出最大的小于jobs[i - 1][0]的数字
            /*
                查找[first, last)区域中第一个不符合 comp 规则的元素
                ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
            */
            //找出第一个结束时间小于等于第i-1个job结束时间的下标k
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int>& job) -> bool {
                return st < job[1];
                }) - jobs.begin();
                dp[i] = max(dp[i-1], dp[k] + jobs[i-1][2]);
        }
        return dp[n];
    }
};