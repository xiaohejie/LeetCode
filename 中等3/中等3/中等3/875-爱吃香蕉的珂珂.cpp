#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	875-�����㽶������
        ʹ�ö��ַ���Bվ���и����ڶ��ַ����ҵ���Ƶ���ǵÿ���
*/
class Solution {
public:
    //�õ�һspeed���ٶȳ�����ô���㽶��Ҫ����ʱ��
    long getTime(vector<int>& piles, int speed) {
        long time = 0;
        for (auto& pile : piles) {
            int curTime = (pile + speed - 1) / speed;
            time += curTime;
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;    //���������ٶ�
        int high = 0;   //��������ٶ�
        for (auto& pile : piles) {
            high = max(high, pile);     //�õ�����ٶ�
        }
        int k = high;
        while (low < high)
        {
            int speed = (high - low) / 2 + low;         //�õ��м��ٶ�
            long time = getTime(piles, speed);      //�õ�speed���ٶȳ��㽶��Ҫ���೤ʱ��
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