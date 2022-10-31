#include<iostream>
#include<vector>
using namespace std;
/*
	886. ���ܵĶ��ַ�
        Ⱦɫ��/���鼯
        ���̣�
        ��ʼ�������˵���ɫΪ0����ʾ��û��Ⱦɫ
        ���������ˣ������ǰ��û��Ⱦɫ����ô������ɫ1�������Ⱦɫ��Ȼ�������в�ϲ����������ɫ2����Ⱦɫ�����Ⱦɫ���̳����˳�ͻ����˵���޷����з��飬����false;
        ��������˶�Ⱦɫ�ɹ�����ô��˵�����Է��飬����true;
*/
class Solution {
    //���з��飬���жϻ᲻����ֳ�ͻ
    bool dfs(int curnode, int nowcolor, vector<int>& color, vector<vector<int>>& g) {
        //���з���
        color[curnode] = nowcolor;
        //�жϻ᲻����ֳ�ͻ
        for (auto& node : g[curnode]) {
            if (color[node] && color[node] == color[curnode]) {
                //����Ѿ������˷��飬���ұ�������һ�飬��˵�������˳�ͻ
                return false;
            }
            //û�б����飬��ͨ��dfs���з��飬������Ҫ������nowcolor��ͬ����
            if (!color[node] && !dfs(node, 3^nowcolor, color, g)) { //�����Ҫʹ����򣬲���ֱ����2���Լ�������дһ��
                //�������false��˵�����ֳ�ͻ
                return false;
            }
        }
        //��󷵻�true;
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1);     //���ڼ�¼�����Ƿ��Ѿ����з��飬0δ���飬1/2�ѷ���
        vector<vector<int>> g(n+1); //��¼��Ը�����һ�����
        //��ʼ����Ը�����һ�����
        for (auto& d : dislikes) {
            g[d[0]].push_back(d[1]);
            g[d[1]].push_back(d[0]);
        }
        //�����ж�
        for (int i = 1; i <= n; i++) {
            //�����û�н��з��飬���ҷ������ֳ�ͻ
            if (color[i] == 0 && !dfs(i, 1, color, g)) {
                return false;
            }
        }
        return true;
    }
};
