#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
    532. �����е� k-diff ����
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
            //�����map���Ѿ�����num[i]
            if (map.find(nums[i]) != map.end()) {
                continue;
            } 
            for (int j = i + 1; j < len; j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    //Ҫ�����ж�nums[i]��nums[j]�Ƿ��ظ����ֹ�
                    int flag = 0;
                    for (auto& num : map[nums[i]]) {
                        //�Ѵ���nums[j]
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
            //���Ҫ���ж�һ��key��value��ȣ���Ϊ�����沿��key��value��
            //̫�鷳
        }
        return count;*/
    }
};