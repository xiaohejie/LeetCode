#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
/*
    ������ 17.09. �� k ����
        ��1����С��
        ��2����̬�滮
*/
class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> factors = { 3, 5, 7 };
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1L);
        heap.push(1L);
        int magic = 0;
        for (int i = 0; i < k; i++) {
            long cur = heap.top();
            heap.pop();
            magic = (int)cur;
            for (int factor : factors) {
                long next = cur * factor;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return magic;
    }
};

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k + 1);
        dp[1] = 1;
        int p3 = 1, p5 = 1, p7 = 1;
        for (int i = 2; i <= k; i++) {
            int num3 = dp[p3] * 3, num5 = dp[p5] * 5, num7 = dp[p7] * 7;
            dp[i] = min(min(num3, num5), num7);
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
            if (dp[i] == num7) {
                p7++;
            }
        }
        return dp[k];
    }
};