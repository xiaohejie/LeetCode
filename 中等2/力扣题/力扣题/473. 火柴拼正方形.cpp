#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
/*
	473. ���ƴ������
*/
class Solution {
public:
    /*
    int gl_target = 0;
    bool backTracking(vector<int>& matchsticks, int k, int target, int startIndex, vector<bool>& used) {
        if (k == 0) return true;   //���ݲ���1
        if (target == 0) return backTracking(matchsticks, k - 1, gl_target, 0, used); //���ݲ���2
        for (int i = startIndex; (i < matchsticks.size()) && (target - matchsticks[i] >= 0); i++) { //���ݲ���3
            if (used[i]) continue;
            used[i] = true;
            if (backTracking(matchsticks, k, target - matchsticks[i], i + 1, used)) return true;
            used[i] = false;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;             //Ԥ����1
        int target = sum / 4, n = matchsticks.size();
        sort(matchsticks.begin(), matchsticks.end());
        if (matchsticks[n - 1] > target) return false; //Ԥ����2
        vector<bool> used(matchsticks.size(), false);
        gl_target = target;
        return backTracking(matchsticks, 4, target, 0, used);
    }*/






    /*
    bool dfs(int index, vector<int>& matchsticks, int edge, vector<int>& edges ) {
        //��ֹ����
        if (index == matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < edges.size(); i++) {
            if(edges[i] + matchsticks[index] > edge){
                continue;
            }
            edges[i] += matchsticks[index];
            if (dfs(index+1, matchsticks, edge, edges)) {
                return true;
            }
            //����
            edges[i] -= matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        //����ͣ�����͵ĳ��Ȳ���4�ı�������false
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum %4 != 0) {
            return false;
        }

        //����
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        //����
        vector<int> edges(4);       //��¼�ĸ��ߵı߳�
        return dfs(0, matchsticks, sum / 4, edges);

    }*/
};