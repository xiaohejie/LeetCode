#include<iostream>
using namespace std;
/*
	754. 到达终点数字
        分析加数学
*/
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int s = 0, n = 0;
        while (s < target || (s - target) % 2) // 没有到达（越过）终点，或者相距奇数
            s += ++n;
        return n;
    }
};