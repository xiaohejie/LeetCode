#include<iostream>
using namespace std;
/*
	754. �����յ�����
        ��������ѧ
*/
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int s = 0, n = 0;
        while (s < target || (s - target) % 2) // û�е��Խ�����յ㣬�����������
            s += ++n;
        return n;
    }
};