#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	934. ��̵���
        ʹ�ù����������
*/
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
        vector<pair<int, int>> island;      //���ڼ�¼��һ�����ļ���
        queue <pair<int, int>> qu;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //��������¼һ������Ⱥ
                if (grid[i][j] == 1) {  //����ǵ���
                    qu.emplace(i, j);   //���õ���Ž�qu������
                    grid[i][j] = -1;
                    while (!qu.empty()) {   //��¼���ڵ���
                        auto [x, y] = qu.front();
                        qu.pop();
                        island.emplace_back(x, y);
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dirs[k][0];
                            int ny = y + dirs[k][1];
                            //����õ�����ھ�Ҳ�ǵ���
                            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1) {
                                qu.emplace(nx, ny);
                                grid[nx][ny] = -1;
                            }
                        }
                    }
                    //����һ������Ⱥ�����궼�Ž�qu������
                    for (auto &&[x, y] : island) {
                        qu.emplace(x, y);
                    }
                    //��������Ⱥ�ϵĵ��죬�ҵ�������һ����Ⱥ����step
                    int step = 0;
                    while (!qu.empty()) {
                        int sz = qu.size();
                        //��������qu
                        for (int i = 0; i < sz; i++) {
                            auto [x, y] = qu.front();
                            qu.pop();
                            for (int k = 0; k < 4; k++) {
                                int nx = x + dirs[k][0];
                                int ny = y + dirs[k][1];
                                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                                    //����õ������Χ��ˮ�򣬽��Ŀ�ˮ�����qu�����У�����¼�Ѿ�������
                                    if (grid[nx][ny] == 0) {
                                        qu.emplace(nx, ny);
                                        grid[nx][ny] = -1;
                                    }
                                    else if (grid[nx][ny] == 1) {
                                        //�����Χ����һ�����죬��˵�����ҵ�
                                        return step;
                                    }
                                }
                            }
                        }
                        step++;
                    }
                }
            }
        }
        return 0;
    }
};