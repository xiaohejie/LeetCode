#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	698. 划分为k个相等的子集
        正常的dfs会出现超时，需要进行优化
        解析：
        类似题目：698、划分为k个相等的子集
                  473、火柴盒拼正方形
                  2305、公平分发饼干
*/
class Solution {
    bool dfs(vector<int>& nums, int k, int num, vector<int>& vec, int index) {
        //递归中止条件
        if (index == nums.size()) {
            //说明已经遍历结束，可以构成
            return true;
        }
        //遍历k条边
        for (int i = 0; i < k; i++) {
            if (nums[index] + vec[i] > num) {
                //当前数加上数组中已有的元素大于num
                continue;
            }
            //优化：当前桶和前一个桶和一样，就直接跳过
            if (i > 0 && vec[i] == vec[i-1]) {
                continue;
            }
            //还有一个优化点：对于第一个求，放到任意一个桶中的效果都是一样的，所以直接规定放到第一个桶中
            if (i >  0 && index == 0) {
                break;
            }

            //两者加上不大于num，就让当前边加上下标为index的数
            vec[i] += nums[index];
            //递归判断下一条边
            if (dfs(nums, k, num, vec, index + 1)) {
                //若下一条边也可以，返回true
                return true;
            }
            //否则的话，进行回溯
            vec[i] -= nums[index];
        }
        //都不满足要求
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
        int num = sum / k;  //得到每个子数组的和
        vector<int> vec(k);
        return dfs(nums, k, num, vec, 0);
    }
};