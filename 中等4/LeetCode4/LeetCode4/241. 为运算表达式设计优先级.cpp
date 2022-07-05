#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	241. 为运算表达式设计优先级
        记忆化搜索
        动态规划
*/

class Solution {
public:
    //该方法用的分治（思考，想）
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        if (exp.size() == 0) return {};
        for (int i = 0; i < exp.size(); i++) {
            char act = exp[i];
            //判断act是否是数学符号
            if (act == '+' || act == '-' || act == '*') {
                //是的话，就对左边和右边的式子进行diffWaysToCompute
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1, exp.size() - i - 1));
                //遍历左右式子得出来的结果（因为左右式子里面可能也有数学符号，所以得出来的是一个数组）
                for (int l_num : left) {
                    for (int r_num : right) {
                        if (act == '+') {
                            ans.push_back(l_num + r_num);
                        }
                        if (act == '-') {
                            ans.push_back(l_num - r_num);
                        }
                        if (act == '*') {
                            ans.push_back(l_num * r_num);
                        }
                    }
                }
            }
        }
        if (ans.size() == 0) ans.push_back(stoi(exp));
        return ans;
    }
};
//官方方法看不懂
class Solution {
public:
    const int ADDITION = -1;
    const int SUBTRACTION = -2;
    const int MULTIOLICATION = -3;
    vector<int> dfs(vector<vector<vector<int>>>& dp, int l, int r, const vector<int> ops) {
        if (dp[l][r].empty()) {
            if (l == r) {
                dp[l][r].push_back(ops[l]);
            }
            else {
                //加2的原因是中间有个符号
                for (int i = l; i < r; i += 2) {
                    //这里看不懂
                    auto left = dfs(dp, l, i, ops);
                    auto right = dfs(dp, i + 2, r, ops);
                    for (auto& lv : left) {
                        for (auto& rv : right) {
                            if (ops[i + 1] == ADDITION) {
                                dp[l][r].push_back(lv + rv);
                            }
                            else if (ops[i + 1] == SUBTRACTION) {
                                dp[l][r].push_back(lv - rv);
                            }
                            else {
                                dp[l][r].push_back(lv * rv);
                            }
                        }
                    }
                }
            }
        }
        return dp[l][r];
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ops;
        for (int i = 0; i < expression.size();) {
            //判断该字符是否是数字
            if (!isdigit(expression[i])) {
                //判断具体是哪一种符号
                if (expression[i] == '+') {
                    ops.push_back(ADDITION);
                }
                else if (expression[i] == '-') {
                    ops.push_back(SUBTRACTION);
                }
                else {
                    ops.push_back(MULTIOLICATION);
                }
                i++;
            }
            else {
                //如果是数字，就得出该数
                int t = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    t = t * 10 + (expression[i] - '0');
                    i++;
                }
                ops.push_back(t);
            }
        }
        //dp[l][r] = {v0, v1, ...}来表示对应表达式ops[l: r]在按不同优先级组合数字和运算符的操作下可能产生的全部可能结果
        vector<vector<vector<int>>> dp((int)ops.size(), vector<vector<int>>((int)ops.size()));
        return dfs(dp, 0, ops.size() - 1, ops);
    }
};