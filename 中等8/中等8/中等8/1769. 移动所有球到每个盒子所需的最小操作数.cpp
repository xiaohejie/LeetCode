#include<iostream>
#include<vector>
using namespace std;
/*
	1769. �ƶ�������ÿ�������������С������
    ʹ��˫��ģ��ѭ��
    ����ͨ��ǰһ�����ӵĲ������õ���һ�����ӵĲ�����
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size();
        vector<int> ans(len);
        for (int i = 0; i < len; i++) {
            int res = 0;
            for (int j = 0; j < len; j++) {
                if (boxes[j] == '1') {
                    res += abs(j - i);
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};