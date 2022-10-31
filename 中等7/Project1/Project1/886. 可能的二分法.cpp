#include<iostream>
#include<vector>
using namespace std;
/*
	886. 可能的二分法
        染色法/并查集
        流程：
        初始化所有人的颜色为0，表示还没有染色
        遍历所有人，如果当前人没有染色，那么就用颜色1对其进行染色，然后将其所有不喜欢的人用颜色2进行染色。如果染色过程出现了冲突，就说明无法进行分组，返回false;
        如果所有人都染色成功，那么就说明可以分组，返回true;
*/
class Solution {
    //进行分组，并判断会不会出现冲突
    bool dfs(int curnode, int nowcolor, vector<int>& color, vector<vector<int>>& g) {
        //进行分组
        color[curnode] = nowcolor;
        //判断会不会出现冲突
        for (auto& node : g[curnode]) {
            if (color[node] && color[node] == color[curnode]) {
                //如果已经进行了分组，并且被分在了一组，就说明出现了冲突
                return false;
            }
            //没有被分组，就通过dfs进行分组，但是需要分在与nowcolor不同的组
            if (!color[node] && !dfs(node, 3^nowcolor, color, g)) { //这边需要使用异或，不能直接用2，自己按流程写一下
                //如果返回false，说明出现冲突
                return false;
            }
        }
        //最后返回true;
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1);     //用于记录该人是否已经进行分组，0未分组，1/2已分组
        vector<vector<int>> g(n+1); //记录不愿意分在一起的人
        //初始化不愿意分在一组的人
        for (auto& d : dislikes) {
            g[d[0]].push_back(d[1]);
            g[d[1]].push_back(d[0]);
        }
        //进行判断
        for (int i = 1; i <= n; i++) {
            //如果还没有进行分组，并且分组后出现冲突
            if (color[i] == 0 && !dfs(i, 1, color, g)) {
                return false;
            }
        }
        return true;
    }
};
