#include<iostream>
#include<vector>
using namespace std;
/*
    移动0：
        设置indexNum，indexNow
        从0开始{
            如果当前数即indexNum != 0{
                用num[indexNow] = num[indexNum]
                indexNow++
                indeNum++
            }否则等于0{
                indexNow不动；
                indexNum++；
            }
            最后从indexNow开始添加0；
            
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