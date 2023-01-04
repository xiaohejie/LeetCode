#include<iostream>
#include<vector>
using namespace std;
/*
	1769. 移动所有球到每个盒子所需的最小操作数
    使用双层模拟循环
    或者通过前一个盒子的操作数得到下一个盒子的操作数
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size();
        vector<int> ans(len);
        for (int i = 0; i < len; i++) {
            int res = 0;
            for (int j = 0; j < len; j++) {
                if (boxes[j] == '1') {
                    res += abs(j - i);
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};