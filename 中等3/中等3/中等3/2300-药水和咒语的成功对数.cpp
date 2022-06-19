#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	2300-ҩˮ������ĳɹ�����
*/
class Solution {
public:
    int helper(vector<int>& potions, int num, long long success) {
        //ʹ�ö��ַ����в���
        int l = -1, r = potions.size();
        while (l + 1 != r) {
            int m = (l + r) / 2;
            //��Ҫ����ǿ��ת��
            long long res = (long long)potions[m] * num;
            if (res < success) {
                //�߽�����ұ�
                l = m;
            }
            else {
                r = m;
            }
        }

        return potions.size() - r;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //��ʼ�����
        vector<int> ans(spells.size(), 0);

        //��potions��������
        sort(potions.begin(), potions.end());

        //��ÿ��spell���ж��ֲ���
        for (int i = 0; i < spells.size(); i++) {
            ans[i] = helper(potions, spells[i], success);
        }
        return ans;
    }
};