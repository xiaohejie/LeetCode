#include<iostream>
using namespace std;
/*
	319. 灯泡开关
        第二轮的时候单数灯泡开着，双数灯泡关着
*/
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n + 0.5);
    }
};