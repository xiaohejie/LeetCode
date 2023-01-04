#include<iostream>
#include<vector>
using namespace std;
/*
	813. ���ƽ��ֵ�͵ķ���
    ��̬�滮
    dp[i][j]��ʾnums������[0��i-1]���г�j������������ƽ��ֵ��
    {
        j = 1��dp[i][j]���Ƕ�Ӧ����[0,i-1]��ƽ��ֵ
        j > 1�����ǿ��Խ�����[0, i-1]�ֳ�[0, x-1]��[x, i-1]�������֣�����x >= j-1����ôdp[i][j]����������Щ�Ϸ����зַ�ʽ��ƽ��ֵ�͵����ֵ
    }
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];        //nums���
        }
        //������̬����
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        //��ʼ����̬����
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;       //dp[i][j]��ʾnums������[0��i-1]���г�j������������ƽ��ֵ��
        }
        //״̬ת������
        for (int j = 2; j <= k; j++) {
            for (int i = j; i <= n; i++) {      //��Ϊi����Ҫ���ڵ���j������i��j��ʼ����
                for (int x = j - 1; x < i; x++) {   //x >= j-1
                    //dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x)��ʾ��ǰx�������зֳ�j-1�����ƽ��ֵ�� + ��x��i-1��num��ƽ��ֵ��
                    //�ڱ���x�������Ƚ�
                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
                }
            }
        }
        return dp[n][k];
    }
};