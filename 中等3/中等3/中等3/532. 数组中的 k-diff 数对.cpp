#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
    532. 数组中的 k-diff 数对
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visited;
        unordered_set<int> res;
        for (int num : nums) {
            //nums[i] - nums[j] == k
            if (visited.count(num - k)) {
                res.emplace(num - k);
            }
            //nums[i] - nums[j] == -k
            if (visited.count(num + k)) {
                res.emplace(num);
            }
            visited.emplace(num);
        }
        return res.size();


        /*
        unordered_map<int, vector<int>> map;
        int count = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            //如果在map中已经存在num[i]
            if (map.find(nums[i]) != map.end()) {
                continue;
            } 
            for (int j = i + 1; j < len; j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    //要进行判断nums[i]和nums[j]是否重复出现过
                    int flag = 0;
                    for (auto& num : map[nums[i]]) {
                        //已存在nums[j]
                        if (num == nums[j]) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        count++;
                        map[nums[i]].push_back(nums[j]);
                    }
                }
            }
            //最后还要在判断一下key和value相等（因为这里面部分key和value）
            //太麻烦
        }
        return count;*/
    }
};