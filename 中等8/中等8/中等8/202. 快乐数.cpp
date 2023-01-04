#include<iostream>
using namespace std;
/*
	202. 快乐数
        使用快慢指针
*/
class Solution {
    int getNext(int n) {
        int ans = 0;
        while (n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int slowNum = n;
        int fastNum = getNext(n);
        while (fastNum != 1 && slowNum != fastNum) {
            slowNum = getNext(slowNum);
            fastNum = getNext(getNext(fastNum));
        }
        return fastNum == 1;
    }
};