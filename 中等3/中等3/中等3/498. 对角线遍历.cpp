#include<iostream>
#include<vector>
using namespace std;
/*
	498. 对角线遍历
        模拟找规律
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        //对角线的分数一共是m+n-1个
        //找出奇对角线和偶对角线的规律
        for (int i = 0; i < m + n - 1; i++) {
            //如果是奇对角线
            if (i % 2) {
                //找到起始位置
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                //然后遍历
                while (x < m && y >= 0) {
                    ans.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
            else {
                //找到起始位置
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                //然后遍历
                while (x >= 0 && y < n) {
                    ans.push_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
        }
        return ans;
    }
};