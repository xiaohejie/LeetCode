#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	934. 最短的桥
        使用广度优先搜索
*/
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
        vector<pair<int, int>> island;      //用于记录第一座岛的集合
        queue <pair<int, int>> qu;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //遍历，记录一座岛屿群
                if (grid[i][j] == 1) {  //如果是岛屿
                    qu.emplace(i, j);   //将该岛屿放进qu队列中
                    grid[i][j] = -1;
                    while (!qu.empty()) {   //记录相邻岛屿
                        auto [x, y] = qu.front();
                        qu.pop();
                        island.emplace_back(x, y);
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dirs[k][0];
                            int ny = y + dirs[k][1];
                            //如果该岛屿的邻居也是岛屿
                            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1) {
                                qu.emplace(nx, ny);
                                grid[nx][ny] = -1;
                            }
                        }
                    }
                    //将第一座岛屿群的坐标都放进qu队列中
                    for (auto &&[x, y] : island) {
                        qu.emplace(x, y);
                    }
                    //遍历岛屿群上的岛屿，找到到达另一岛屿群所需step
                    int step = 0;
                    while (!qu.empty()) {
                        int sz = qu.size();
                        //遍历队列qu
                        for (int i = 0; i < sz; i++) {
                            auto [x, y] = qu.front();
                            qu.pop();
                            for (int k = 0; k < 4; k++) {
                                int nx = x + dirs[k][0];
                                int ny = y + dirs[k][1];
                                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                                    //如果该岛屿的周围是水域，将改口水鱼放入qu队列中，并记录已经遍历过
                                    if (grid[nx][ny] == 0) {
                                        qu.emplace(nx, ny);
                                        grid[nx][ny] = -1;
                                    }
                                    else if (grid[nx][ny] == 1) {
                                        //如果周围是另一座岛屿，则说明已找到
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