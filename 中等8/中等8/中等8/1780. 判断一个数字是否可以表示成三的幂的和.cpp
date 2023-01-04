#include<iostream>
#include<vector>
/*
    转换成3进制
*/
using namespace std;
/*
	1780. 判断一个数字是否可以表示成三的幂的和
*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> vec;
        while (n != 0) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};