#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	241. Ϊ������ʽ������ȼ�
        ���仯����
        ��̬�滮
*/

class Solution {
public:
    //�÷����õķ��Σ�˼�����룩
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        if (exp.size() == 0) return {};
        for (int i = 0; i < exp.size(); i++) {
            char act = exp[i];
            //�ж�act�Ƿ�����ѧ����
            if (act == '+' || act == '-' || act == '*') {
                //�ǵĻ����Ͷ���ߺ��ұߵ�ʽ�ӽ���diffWaysToCompute
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1, exp.size() - i - 1));
                //��������ʽ�ӵó����Ľ������Ϊ����ʽ���������Ҳ����ѧ���ţ����Եó�������һ�����飩
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
//�ٷ�����������
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
                //��2��ԭ�����м��и�����
                for (int i = l; i < r; i += 2) {
                    //���￴����
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
            //�жϸ��ַ��Ƿ�������
            if (!isdigit(expression[i])) {
                //�жϾ�������һ�ַ���
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
                //��������֣��͵ó�����
                int t = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    t = t * 10 + (expression[i] - '0');
                    i++;
                }
                ops.push_back(t);
            }
        }
        //dp[l][r] = {v0, v1, ...}����ʾ��Ӧ���ʽops[l: r]�ڰ���ͬ���ȼ�������ֺ�������Ĳ����¿��ܲ�����ȫ�����ܽ��
        vector<vector<vector<int>>> dp((int)ops.size(), vector<vector<int>>((int)ops.size()));
        return dfs(dp, 0, ops.size() - 1, ops);
    }
};