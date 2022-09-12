#include<iostream>
#include<vector>
using namespace std;
/*
	667. 优美的排列 II
        从特殊情况到一般情况（脑经急转弯的题目）
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
                //需要进行判断i是否等于j，否则可能插入两个相同的数
                ans.push_back(j);
            }
        }
        return ans;
    }
};