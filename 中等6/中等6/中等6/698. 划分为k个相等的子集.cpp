#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	698. ����Ϊk����ȵ��Ӽ�
        ������dfs����ֳ�ʱ����Ҫ�����Ż�
        ������
        ������Ŀ��698������Ϊk����ȵ��Ӽ�
                  473������ƴ������
                  2305����ƽ�ַ�����
*/
class Solution {
    bool dfs(vector<int>& nums, int k, int num, vector<int>& vec, int index) {
        //�ݹ���ֹ����
        if (index == nums.size()) {
            //˵���Ѿ��������������Թ���
            return true;
        }
        //����k����
        for (int i = 0; i < k; i++) {
            if (nums[index] + vec[i] > num) {
                //��ǰ���������������е�Ԫ�ش���num
                continue;
            }
            //�Ż�����ǰͰ��ǰһ��Ͱ��һ������ֱ������
            if (i > 0 && vec[i] == vec[i-1]) {
                continue;
            }
            //����һ���Ż��㣺���ڵ�һ���󣬷ŵ�����һ��Ͱ�е�Ч������һ���ģ�����ֱ�ӹ涨�ŵ���һ��Ͱ��
            if (i >  0 && index == 0) {
                break;
            }

            //���߼��ϲ�����num�����õ�ǰ�߼����±�Ϊindex����
            vec[i] += nums[index];
            //�ݹ��ж���һ����
            if (dfs(nums, k, num, vec, index + 1)) {
                //����һ����Ҳ���ԣ�����true
                return true;
            }
            //����Ļ������л���
            vec[i] -= nums[index];
        }
        //��������Ҫ��
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % k != 0) {
            return false;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int num = sum / k;  //�õ�ÿ��������ĺ�
        vector<int> vec(k);
        return dfs(nums, k, num, vec, 0);
    }
};