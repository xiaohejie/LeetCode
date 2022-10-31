#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	1235. �滮��ְ����
        ʹ�ö�̬�滮 + ���ֲ���
        ˼·��
        ��ѡ��i����������ô��󱨳����ǰi-1����������󱨳�
        ѡ��i�����������ڹ���ʱ�䲻���ص�����j����������endTime[j] <= startTime[i]��j��ô��󱨳����ǰ j ����������󱨳����profit[i]
*/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        //����������ʼʱ���Լ�н�ʷ���һ��
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = { startTime[i], endTime[i], profit[i] };
        }
        //�������򣬰��ս���ʱ���������
        sort(jobs.begin(), jobs.end(), [](const vector<int>& job1, const vector<int>& job2)-> bool {
            return job1[1] < job2[1];
            });
        vector<int> dp(n+1);
        for (int i = 1; i <= n; i++) {
            //�ҳ�����С��jobs[i - 1][0]������
            /*
                ����[first, last)�����е�һ�������� comp �����Ԫ��
                ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
            */
            //�ҳ���һ������ʱ��С�ڵ��ڵ�i-1��job����ʱ����±�k
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int>& job) -> bool {
                return st < job[1];
                }) - jobs.begin();
                dp[i] = max(dp[i-1], dp[k] + jobs[i-1][2]);
        }
        return dp[n];
    }
};