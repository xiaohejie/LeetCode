#include<iostream>
#include<vector>
using namespace std;
/*
	��ָ Offer II 091. ��ˢ����
        n�ʺ�ļ򻯰汾
        ���ݷ������򵥵ķ��������ö�̬�滮��
*/
//ʹ�û��ݷ������⣬��Ҳ�Ҳ�����
/*
class Solution {
    int row = 0, col = 0;
    int minCost = INT_MAX;
public:
    void backTrack(vector<vector<int>>& costs, int nowRow, int nowCol, int row, int col, int cost) {
        if (nowRow == row) {
            //��������
            minCost = min(minCost, cost);
            return;
        }
        if (nowCol == col) {
            //˵���Ѿ���������β
            nowCol = 0;
        }
        //����
        for (int i = nowCol; i < col; i++) {
            cost += costs[nowRow][nowCol];
            backTrack(costs, nowRow+1, nowCol+1, row, col, cost);
            cost -= costs[nowRow][nowCol];
        }
    }
    int minCost(vector<vector<int>>& costs) {
        row = costs.size(), col = costs[0].size();
        int cost = 0;
        backTrack(costs, 0, 0, row, col, cost);
    }
};*/

//ʹ�ö�̬�滮
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        //������ʼ��̬���������г�ʼ��
        vector<int> dp(3);
        for (int i = 0; i < 3; i++) {
            dp[i] = costs[0][i];
        }

        //״̬ת�Ʒ��̣��ӵ�һ�����ӿ�ʼ��
        for (int i = 1; i < n; i++) {
            //ʣ�ද̬����
            vector<int> dpNew(3);
            //�������ѡ��������ɫ�Ļ���
            for (int j = 0; j < 3; j++) {
                dpNew[j] = min(dp[(j + 1)%3], dp[(j + 2) % 3]) + costs[i][j];
            }
            dp = dpNew;
        }
        //�ҵ���Сֵ
        int minV = INT_MAX;
        for (int i = 0; i < 3; i++) {
            minV = min(minV, dp[i]);
        }
        return minV;
    }
};