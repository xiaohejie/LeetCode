#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	873. ���쳲����������еĳ���
        ʹ�ö�̬�滮��
            ��Ҫʹ�ö�ά����dp����arr[i]��arr[j]��β���쳲����������еĳ���
            һά�������dp�����㣬��������Ӵ���쳲�������������Ҫ��
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, int>nMap;
        int len = arr.size();
        //������̬����
        vector<vector<int>> dp(len, vector<int>(len, 2));
        for (int i = 0; i < len; i++) {
            //���ں����õ�idx(arr[i]-arr[j])
            nMap[arr[i]] = i;
            //�������п��ܵ�j
            for (int j = i - 1; j >= 0; j--) {
                //�����ֵdif
                int dif = arr[i] - arr[j];
                //�����ֵ��arr[j]��˵���ҹ�ͷ�ˣ���ֱ���˳�
                if (dif >= arr[j]) {
                    break;
                }
                //����Ļ�����dif�ڲ���arr�У�����ڵĻ�����״̬ת��
                if (dif < arr[j] && nMap.find(dif) != nMap.end()) {
                    //��Ҫȷ��dp[i][j]�����ֵ
                    dp[i][j] = max(dp[j][nMap[dif]] + 1, dp[i][j]);
                    //����ans
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        //������ans == 2����ô˵��û��쳲��������У���Ϊ쳲��������е���С������3
        return ans == 2 ? 0 : ans;
    }
};