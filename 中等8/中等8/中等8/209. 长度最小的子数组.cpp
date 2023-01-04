#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
	209. ������С��������
    ���������ᳬ��ʱ�����
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target) {
            return 0;
        }
        else if (sum == target) {
            return nums.size();
        }
        int len = nums.size();
        vector<int> vec(len);
        for (int i = 0; i < len; i++) {
            int s = 0, count = 0;
            for (int j = i; j < len; j++) {
                s += nums[j];
                count++;
                if (s >= target) {      //��i��j�ĺʹ��ڵ���target���Ϳ��Դ��뵽vec������
                    vec[i] = count;
                    break;
                }
            }
            if (s < target) {       //�������������������
                vec[i] = INT_MAX;
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < len; i++) {
            if (ans > vec[i]) {
                ans = vec[i];
            }
        }
        return ans;
    }
};

/*
    ǰ׺�ͺͶ��ֲ���
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

    }
};

/*
    ��������
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //ʹ�û�������
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < len)
        {
            sum += nums[end];
            while (sum >= target) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

