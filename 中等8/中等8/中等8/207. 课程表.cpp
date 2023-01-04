#include<iostream>
#include<vector>
using namespace std;
/*
	207. �γ̱�
    ʹ����������
*/
class Solution {
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:
    //������ȱ������ſ�
    void dfs(int u) {
        visited[u] = 1;     //����״̬
        for (int v : edges[u]) {        //����ѡ�޵�u�ſ�֮�󣬿�������Щ��
            if (visited[v] == 0) {  //�����v�ſ�û�ޣ����н�����ȱ���
                dfs(v);
                if (!valid) {       //��������˻������˳�
                    return;
                }
            }
            else if (visited[v] == 1) { //��ʾ��v�ſ�Ҳ�������У��ͻ���ֻ����˳�
                valid = false;
                return ;
            }
        }
        visited[u] = 2;     //��ʾ��������������û�г��ֻ�
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //ȷ��������С
        edges.resize(numCourses);
        visited.resize(numCourses);
        //��ʼ��edges��ѡ�˸ÿο�������Щ��
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        //����numCouses�ſΣ�����valid��Ϊ���ж���;��û�л����л��Ļ�ֱ���˳�
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {     //û�б��������ſ��Խ���������ȱ���
                dfs(i);
            }
        }
        return valid;
    }
};