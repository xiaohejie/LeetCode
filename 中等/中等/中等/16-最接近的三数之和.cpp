#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
    最接近的三数之和：
    思路：利用双指针
            update函数：判断谁离target更近
            排序
          for(i = 0; i < size; i++){
                //确保i不重复
                if(i > 0 && s[i] == s[i + 1]){continue;}
                int j = i + 1, k = size - 1;
                while(j < k){
                    计算三数之和
                    进行update判断

                    如果直接等于target的话，直接退出
                    否则{
                        如果sum < target{
                            j++;
                            还要判断两数字（j和j+1）是否相等
                        }else{
                            k--;
                            判断两数（k和k-1）是否相等
                        }
                    }
                }
          } 
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int best = 1e7;
        //根据差值来更新best（使用的是lamada表达式）
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };
        
        for (int i = 0; i < len; i++) {
            //判断两数是否相等
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                }
                update(sum);
                if (sum < target) {
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j]) {
                        j0++;
                    } 
                    j = j0;
                }
                else {
                    int k0 = k - 1;
                    while(j < k0 && nums[k0] == nums[k]){
                        k0--;
                    }
                    k = k0;
                }
            }
        }
        return best;
    }
};