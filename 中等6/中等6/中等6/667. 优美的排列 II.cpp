#include<iostream>
#include<vector>
using namespace std;
/*
	667. ���������� II
        �����������һ��������Ծ���ת�����Ŀ��
*/
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        for (int i = 1; i < n - k; i++) {
            ans.push_back(i);
        }
        for (int i = n - k, j = n; i <= j; ++i,--j) {
            ans.push_back(i);
            if (i != j) {
                //��Ҫ�����ж�i�Ƿ����j��������ܲ���������ͬ����
                ans.push_back(j);
            }
        }
        return ans;
    }
};