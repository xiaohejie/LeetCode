#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	324. �ڶ����� II
        ���ף���ʱ�临�Ӷ�O(n)���߿ռ临�Ӷ�O(1)����ʵ��
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> lnums, rnums;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (i < (len + 1) / 2) {
                cout << nums[i] << "-";
                lnums.push_back(nums[i]);
            }
            else {
                cout << nums[i] << "+";
                rnums.push_back(nums[i]);
            }
        }
        reverse(lnums.begin(), lnums.end());
        reverse(rnums.begin(), rnums.end());
        //��nums��������
        int lidx = 0, ridx = 0;
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                nums[i] = lnums[lidx++];
            }
            else {
                nums[i] = rnums[ridx++];
            }
        }
        if (lnums.size() < rnums.size()) {
            nums[len - 1] = rnums[rnums.size() - 1];
        }
        if (lnums.size() > rnums.size()) {
            nums[len - 1] = lnums[lnums.size() - 1];
        }
    }
};