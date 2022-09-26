#include<iostream>
#include<vector>
using namespace std;
/*
	������ 17.19. ��ʧ����������
        ʹ��λ����
        ע��������ר����ʧ���������ֽⷨ
*/
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int len = nums.size();
        int N = len + 2;
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum ^= nums[i];
        }
        for (int i = 1; i <= N; i++) {
            sum ^= i;
        }
        //�õ�������������sum
        //ʹ��x&-x���x�Ķ����Ʊ�ʾ�����λ��1����lsb����Ҫ
        int lsb = (sum == INT_MIN ? sum : sum & (-sum));
        int num1 = 0, num2 = 0;
        for (auto& num : nums) {
            if (num & lsb) {
                num1 ^= num;
            }
            else {
                num2 ^= num;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (i & lsb) {
                num1 ^= i;
            }
            else {
                num2 ^= i;
            }
        }
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
};