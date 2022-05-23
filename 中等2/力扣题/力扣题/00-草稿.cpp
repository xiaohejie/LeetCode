#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/* 961. �ڳ��� 2N ���������ҳ��ظ� N �ε�Ԫ�� */
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