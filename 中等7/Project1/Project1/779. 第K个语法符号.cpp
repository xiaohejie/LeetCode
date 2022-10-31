#include<iostream>
#include<vector>
using namespace std;
/*
	779. ��K���﷨����
        �ݹ飨�ҳ���n�е�k���ַ����1�е����0���ݱ��ϵ��
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (k == 1) {
            return 0;   //���ϱ������˵�1�У��򷵻ؽ��
        }
        if (k > ( 1 << n-2)) {      //1 << n-2����1����n-2λ   0000 0001 --->  0000 1000
            return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2)));   // ����ڡ���ɫ���䡱��������һ��ֵ�෴����1������򣬾���ȥ�� 1^0 = 1 1^1 = 0��
        }
        else {
            return kthGrammar(n-1, k);   // ����ڡ���ɫ���䡱��������һ��ֵ��ͬ
        }
    }
};

//�÷������У��������û�취���������ͣ�
class Solution {
public:
    int kthGrammar(int n, int k) {
        vector<vector<int>> ans(n+1);
        ans[1].push_back(0);
        for (int i = 2; i <= n; i++) {
            //�ӵڶ��п�ʼ����������һ�е���
            for (int j = 0; j < ans[i - 1].size(); j++) {
                if (ans[i - 1][j] == 0) {
                    ans[i].push_back(0);
                    ans[i].push_back(1);
                }
                else {
                    ans[i].push_back(1);
                    ans[i].push_back(0);
                }
            }
        }
        //�������һ�еĵ�k-1����
        return ans[n][k - 1];
    }
};