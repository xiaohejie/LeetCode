#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
/*
    ��ӽ�������֮�ͣ�
    ˼·������˫ָ��
            update�������ж�˭��target����
            ����
          for(i = 0; i < size; i++){
                //ȷ��i���ظ�
                if(i > 0 && s[i] == s[i + 1]){continue;}
                int j = i + 1, k = size - 1;
                while(j < k){
                    ��������֮��
                    ����update�ж�

                    ���ֱ�ӵ���target�Ļ���ֱ���˳�
                    ����{
                        ���sum < target{
                            j++;
                            ��Ҫ�ж������֣�j��j+1���Ƿ����
                        }else{
                            k--;
                            �ж�������k��k-1���Ƿ����
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
        //���ݲ�ֵ������best��ʹ�õ���lamada���ʽ��
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };
        
        for (int i = 0; i < len; i++) {
            //�ж������Ƿ����
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