#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	875-爱吃香蕉的珂珂
        使用二分法（B站上有个关于二分法查找的视频，记得看）
*/
class Solution {
public:
    //得到一speed的速度吃完这么多香蕉需要多少时间
    long getTime(vector<int>& piles, int speed) {
        long time = 0;
        for (auto& pile : piles) {
            int curTime = (pile + speed - 1) / speed;
            time += curTime;
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;    //假设最慢速度
        int high = 0;   //假设最快速度
        for (auto& pile : piles) {
            high = max(high, pile);     //得到最快速度
        }
        int k = high;
        while (low < high)
        {
            int speed = (high - low) / 2 + low;         //得到中间速度
            long time = getTime(piles, speed);      //得到speed的速度吃香蕉，要花多长时间
            if (time <= h) {
                k = speed;
                high = speed;
            }
            else {
                low = speed + 1;
            }
        }
        return k;
    }
};