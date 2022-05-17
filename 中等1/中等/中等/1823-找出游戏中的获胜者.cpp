#include<iostream>
#include<queue>
using namespace std;
/*
	�ҳ���Ϸ�еĻ�ʤ�ߣ�
		ʹ�ö���+ģ��
		��1����1-n�������뵽������
		��2��Ȼ�����ѭ��{
			����ͷ���¼����β����ԭ���Ķ�ͷ����ɾ���������õ�k�����ڶ�ͷ
			����ͷ����ɾ����������ɾ���˵�k������
		}
		��3�����ض�ͷ
*/
class Solution {
public:
	int findTheWinner(int n, int k) {
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			//��1-n���뵽������
			q.emplace(i);
		}
		//������Ϸģ��
		while (q.size() > 1) {
			//���Ͻ���k��ѭ��������k�����ŵ�ͷ��
			for (int i = 1; i <= k; i++) {
				q.emplace(q.front());
				q.pop();
			}
			//�ٽ���ɾ��
			q.pop();
		}
		return q.front();
	}
};