#include<iostream>
#include<vector>
using namespace std;
/*
	134. 加油站
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        //枚举起点位置
        for (int i = 0; i < n;) {
            int cnt = 0, left = 0;        //cnt表示路过的加油站的数量，left是指剩余油量
            while (cnt < n) {
                //由于加油站是环形的，所以重新计算下标
                int k = (i + cnt) % n;
                //计算到达j后的剩余油量
                left += gas[k] - cost[k];
                if (left < 0) {
                    break;
                }
                cnt++;
            }
            //表明以i为起点，可以到达终点
            if (cnt == n) {
                return i;
            }
            //否则的话，说明以i到i+j为起点，都到不了终点（画图理解为什么到不了）
            i = i + cnt + 1;
        }
        return -1;
    }
};