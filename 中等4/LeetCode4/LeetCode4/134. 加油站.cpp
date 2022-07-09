#include<iostream>
#include<vector>
using namespace std;
/*
	134. ����վ
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        //ö�����λ��
        for (int i = 0; i < n;) {
            int cnt = 0, left = 0;        //cnt��ʾ·���ļ���վ��������left��ָʣ������
            while (cnt < n) {
                //���ڼ���վ�ǻ��εģ��������¼����±�
                int k = (i + cnt) % n;
                //���㵽��j���ʣ������
                left += gas[k] - cost[k];
                if (left < 0) {
                    break;
                }
                cnt++;
            }
            //������iΪ��㣬���Ե����յ�
            if (cnt == n) {
                return i;
            }
            //����Ļ���˵����i��i+jΪ��㣬���������յ㣨��ͼ���Ϊʲô�����ˣ�
            i = i + cnt + 1;
        }
        return -1;
    }
};