#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	556. ��һ������Ԫ�� III������һ���������ƣ�
    {
        �Ӻ���ǰ����n��ֱ���ҵ�ǰһ����С����һ�������±�
        ���������������û�еĻ�����ֱ�ӷ���-1
        ����Ļ�{
            �ٴν��б�����ֱ���ҵ�nums[j] < nums[i]���±�
        }
        ����i��jλ��
        Ȼ�����е���������û�
    }
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        int i = nums.length() - 2;
        while (i >= 0 && nums[i] > nums[i+1]) {
            i--;
        }
        if (i < 0) {
            return -1;
        }
        int j = nums.length() - 1;
        while (j >= 0 && nums[i] > nums[j]) {
            j--;
        }

        //����i��j��λ��
        swap(nums[i], nums[j]);
        //�ٽ��е���
        reverse(nums.begin() + i + 1, nums.end());
        int ans = stoi(nums);
        return ans;
    }
};