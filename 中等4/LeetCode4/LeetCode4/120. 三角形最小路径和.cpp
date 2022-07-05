#include<iostream>
#include<vector>
using namespace std;
/*
	120. ��������С·����
        ʹ�ö�̬�滮    
*/
//�÷����Ǵ���������
class Solution {
public:
    int res = INT_MAX;
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> ans(row, vector<int>(row));
        //���г�ʼ��
        ans[0][0] = triangle[0][0];
        for (int i = 1; i < row; i++) {
            //ÿ�еĵ�һ�У�������һ��û��ǰһ��
            ans[i][0] = ans[i - 1][0] + triangle[i][0];
            //����ÿ�е������У������һ��
            for (int j = 1; j < i; j++) {
                ans[i][j] = min(ans[i - 1][j - 1], ans[i-1][j]) + triangle[i][j];
            }
            //���һ�У�����û����һ��
            ans[i][i] = ans[i - 1][i - 1] + triangle[i][i];
        }
        //�ҳ����һ�е���Сֵ
        for (int i = 0; i < row; i++) {
            res = min(res, ans[row][i]);
        }
        return res;
    }
};
//����һ���Ǵ������ϣ���Ҫ���������ϣ����ֱ�ӷ��أ�����Ҫ����Сֵ
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};