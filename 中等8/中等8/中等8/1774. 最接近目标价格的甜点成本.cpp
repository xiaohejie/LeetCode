#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	1774. 最接近目标价格的甜点成本
    回溯法或者动态规划
*/
class Solution {
    //toppingCosts：配料价格，p：当前配料表下标，curCost：当前的花费，res：最优方案的消费，target：目标消费 
    void dfs(const vector<int>& toppingCosts, int p, int curCost, int& res, const int& target) {
        if (abs(res - target) < curCost - target) {//如果此时差值已经大于我们已有最优方案的差值，停止搜索，回溯
            return;
        }else if (abs(res - target) >= abs(curCost - target)) { //如果此时的差值小于等于最优方案的差值，判断
            //进行判断
            if (abs(res - target) > abs(curCost - target)) {    //如果差值小于最优方案的差值，更新
                res = curCost;
            }
            else if (abs(res - target) == abs(curCost - target)) {  //如果等于，比较然后更新
                res = min(res, curCost);
            }
        }
        if (p == toppingCosts.size()) {     //搜索结束，回溯
            return;
        }
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, res, target);
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p], res, target);
        dfs(toppingCosts, p + 1, curCost, res, target);
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = *min_element(baseCosts.begin(), baseCosts.end());     //找到toppingCosts里的最小值
        //对每种冰淇淋基料进行回溯
        for (auto& b : baseCosts) {
            dfs(toppingCosts, 0, b, res, target);
        }
        return res;
    }
};

//动态规划（没看懂）
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int x = *min_element(baseCosts.begin(), baseCosts.end());       //假设基料的最小开销
        if (x >= target) {
            return x;
        }
        //创建动态容器
        vector<bool> can(target + 1, false);    //can[i]表示甜品制作开销为i是否符合方案
        //初始化
        int res = 2 * target - x;           //使用基料后，还剩的部分res，进行初始化（没看懂）
        for (auto& b : baseCosts) {
            if (b <= target) {
                can[b] = true;
            }
            else {
                res = min(res, b);      //这一部分也没看懂
            }
        }
        for (auto& t : toppingCosts) {
            for (int count = 0; count < 2; count++) {
                for (int i = target; i; --i) {
                    if (can[i] && i + t > target) {
                        res = min(res ,i + t);
                    }
                    if (i - t > 0) {
                        can[i] = can[i] | can[i - t];
                    }
                }
            }
        }
        for (int i = 0; i <= res - target; ++i) {
            if (can[target - i]) {
                return target - i;
            }
        }
        return res;
    }
};