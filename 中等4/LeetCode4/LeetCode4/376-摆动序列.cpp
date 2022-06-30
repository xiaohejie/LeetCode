#include<iostream>
#include<vector>
using namespace std;
/*
	376-�ڶ�����
        ��̬�滮
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if(len == 1){
            return 1;
        }
        vector<int> up(len), down(len);
        //�����ʼ״̬
        up[0] = down[0] = 1;
        //״̬ת�Ʒ���
        for (int i = 1; i < len; i++) {
            if (nums[i] > nums[i - 1]) {
                //����
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1]) {
                //���и���
                up[i] = up[i - 1];
                down[i] = max(up[i] + 1, down[i - 1]);
            }
            else
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[len-1], down[len-1]);
    }
};