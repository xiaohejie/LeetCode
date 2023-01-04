#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	1774. ��ӽ�Ŀ��۸�����ɱ�
    ���ݷ����߶�̬�滮
*/
class Solution {
    //toppingCosts�����ϼ۸�p����ǰ���ϱ��±꣬curCost����ǰ�Ļ��ѣ�res�����ŷ��������ѣ�target��Ŀ������ 
    void dfs(const vector<int>& toppingCosts, int p, int curCost, int& res, const int& target) {
        if (abs(res - target) < curCost - target) {//�����ʱ��ֵ�Ѿ����������������ŷ����Ĳ�ֵ��ֹͣ����������
            return;
        }else if (abs(res - target) >= abs(curCost - target)) { //�����ʱ�Ĳ�ֵС�ڵ������ŷ����Ĳ�ֵ���ж�
            //�����ж�
            if (abs(res - target) > abs(curCost - target)) {    //�����ֵС�����ŷ����Ĳ�ֵ������
                res = curCost;
            }
            else if (abs(res - target) == abs(curCost - target)) {  //������ڣ��Ƚ�Ȼ�����
                res = min(res, curCost);
            }
        }
        if (p == toppingCosts.size()) {     //��������������
            return;
        }
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, res, target);
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p], res, target);
        dfs(toppingCosts, p + 1, curCost, res, target);
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = *min_element(baseCosts.begin(), baseCosts.end());     //�ҵ�toppingCosts�����Сֵ
        //��ÿ�ֱ���ܻ��Ͻ��л���
        for (auto& b : baseCosts) {
            dfs(toppingCosts, 0, b, res, target);
        }
        return res;
    }
};

//��̬�滮��û������
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int x = *min_element(baseCosts.begin(), baseCosts.end());       //������ϵ���С����
        if (x >= target) {
            return x;
        }
        //������̬����
        vector<bool> can(target + 1, false);    //can[i]��ʾ��Ʒ��������Ϊi�Ƿ���Ϸ���
        //��ʼ��
        int res = 2 * target - x;           //ʹ�û��Ϻ󣬻�ʣ�Ĳ���res�����г�ʼ����û������
        for (auto& b : baseCosts) {
            if (b <= target) {
                can[b] = true;
            }
            else {
                res = min(res, b);      //��һ����Ҳû����
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