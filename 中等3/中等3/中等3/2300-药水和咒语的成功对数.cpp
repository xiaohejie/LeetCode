#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	2300-药水和咒语的成功对数
*/
class Solution {
public:
    int helper(vector<int>& potions, int num, long long success) {
        //使用二分法进行查找
        int l = -1, r = potions.size();
        while (l + 1 != r) {
            int m = (l + r) / 2;
            //需要进行强制转换
            long long res = (long long)potions[m] * num;
            if (res < success) {
                //边界点在右边
                l = m;
            }
            else {
                r = m;
            }
        }

        return potions.size() - r;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //初始化输出
        vector<int> ans(spells.size(), 0);

        //对potions进行排序
        sort(potions.begin(), potions.end());

        //对每个spell进行二分查找
        for (int i = 0; i < spells.size(); i++) {
            ans[i] = helper(potions, spells[i], success);
        }
        return ans;
    }
};