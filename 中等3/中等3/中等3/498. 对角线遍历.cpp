#include<iostream>
#include<vector>
using namespace std;
/*
	498. �Խ��߱���
        ģ���ҹ���
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        //�Խ��ߵķ���һ����m+n-1��
        //�ҳ���Խ��ߺ�ż�Խ��ߵĹ���
        for (int i = 0; i < m + n - 1; i++) {
            //�������Խ���
            if (i % 2) {
                //�ҵ���ʼλ��
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                //Ȼ�����
                while (x < m && y >= 0) {
                    ans.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
            else {
                //�ҵ���ʼλ��
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                //Ȼ�����
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