#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
/*
	1785. 构成特定和需要添加的最少元素
*/
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        //long long sum = accumulate(nums.begin(), nums.end(), 0);
        long long sum = 0;
        for (auto& num : nums) {
            sum += num;
        }
        if (sum == goal) {
            return 0;
        }
        long long num = abs(goal - sum);       //计算剩下要加多大的数
        return (num + limit - 1) / limit;
        //cout << num << endl;
        /*int count = 0;
        while (num) {
            if (num <= limit) {
                count++;
                break;
            }
            count = num / limit;
            num %= limit;
        }
        return count;*/
    }
};