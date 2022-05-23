#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/* 961. 在长度 2N 的数组中找出重复 N 次的元素 */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto& num : nums) {
            map[num]++;
        }
        for (auto& m : map) {
            if (m.second == nums.size() / 2) {
                return m.first;
            }
        }   
        return NULL;
    }
};