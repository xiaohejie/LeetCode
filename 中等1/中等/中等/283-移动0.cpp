#include<iostream>
#include<vector>
using namespace std;
/*
    �ƶ�0��
        ����indexNum��indexNow
        ��0��ʼ{
            �����ǰ����indexNum != 0{
                ��num[indexNow] = num[indexNum]
                indexNow++
                indeNum++
            }�������0{
                indexNow������
                indexNum++��
            }
            ����indexNow��ʼ���0��
            
        }
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int indexNum = 0;
        int indexNow = 0;
        while (indexNum < nums.size()) {
            if (nums[indexNum] != 0) {
                nums[indexNow] = nums[indexNum];
                indexNow++;
            }
            indexNum++;
        }
        for (int i = indexNow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};