#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
/*
	��ָ Offer II 115. �ؽ�����
         ��������
*/
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        //�ҳ�sequences���е���̳����У�Ψһ����nums���бȽϣ���Ψһֱ��false��
        int n = nums.size();
        vector<int> indegresses(n+1);       //�����洢������ȣ�ʹ��n+1����Ϊ��i-n��������0����ҲҪ�Ž�ȥ
        vector<unordered_set<int>> graph(n + 1);  //�����洢sequences��ɵ�����ͼ

        for (auto& sequence : sequences) {
            for (int i = 1; i < sequence.size(); i++) {
                //��sequence�е��ַ��Ⱥ�˳����ͼ��next��Ӧ����ȼ�1
                int prev = sequence[i - 1], next = sequence[i];
                if (!graph[prev].count(next)) {
                    //if�Ƿ�ֹsequence�����ظ�
                    graph[prev].emplace(next);      //��¼���ַ�������ַ�
                    indegresses[next]++;            //��¼�ַ���λ��
                }
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegresses[i] == 0) {
                //ѡ�����Ϊ0�����
                q.push(i);
            }
        }
        while (!q.empty()) {
            if (q.size() > 1) {
                //�������������ϵ����Ϊ0˵����Ψһ
                return false;
            }
            int num = q.front();
            q.pop();
            for (int next : graph[num]) {
                indegresses[next]--;
                //֮ǰ�Ľ������ˣ���������ָ�������ȼ�1
                if (indegresses[next] == 0) {
                    q.push(next);
                }
            }
        }
        return true;
    }
};

