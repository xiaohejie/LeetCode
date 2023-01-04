#include<iostream>
#include<vector>
using namespace std;
/*
	775. ȫ�ֵ�����ֲ�����
*/
class Solution {
public:
    //��ʱ
    /*bool isIdealPermutation(vector<int>& nums) {
        int countA = 0, countB = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] > nums[j]){
                    countA++;
                }
            }
        }
        for (int i = 0; i < len-1; i++) {
            if (nums[i] > nums[i+1]) {
                countB++;
            }
        }
        return countA == countB;
    }*/

    //һ���ֲ�����һ����һ��ȫ�ֵ��ã����ֻҪ�ж������оֲ����õ������Ƿ���ȫ�ֵ��õ�������ȣ�ֻ��Ҫ�����û�зǾֲ����þͿ�����
    //����ķǾֲ�����ָ����nums[i] > nums[j]������i < j-1���������ڵ㣬��Ȼ����nums[i] > nums[j]��
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), minStuff = nums[n - 1];
        for (int i = n - 3; i >= 0; i--) {
            //�ж���û��ȫ�ֵ��ã������Ǿֲ�����
            if (nums[i] > minStuff) {
                return false;
            }
            //��û��ȫ�ֵ��ã��������ǰ�����ж�
            minStuff = min(minStuff, nums[i + 1]);
        }
        return true;
    }
};