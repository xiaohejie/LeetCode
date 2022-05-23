#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
    
*/
class Solution {
public:
    //备忘录，记录number有没被判断过
    unordered_map<int, bool> memo;
    bool backTrack(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal) {
        //如果memo中没有该number
        if (!memo.count(usedNumbers)) {
            bool res = false;           //使用usedNumber的结果
            //遍历
            for (int i = 0; i < maxChoosableInteger; i++) {
                if (((usedNumbers >> i) & 1) == 0) {        //判断该数有没有被使用过
                    //如果当前数加上i+1大于desiredTotal，则为true；
                    if (i + 1 + currentTotal >= desiredTotal) {
                        res = true;
                        break;
                    }
                    //看另一个选手
                    if (!backTrack(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1)) {
                        res = true;
                        break;
                    }
                }
            }
            memo[usedNumbers] = res;
        }
        //有的话，直接返回memo[usedNumber]
        return memo[usedNumbers];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //所有数相加都小于desiredTotal， 直接返回false；
        if ((maxChoosableInteger * (maxChoosableInteger+1)) / 2 < desiredTotal) {
            return false;  
        }
        //否则使用递归
        return backTrack(maxChoosableInteger, 0, desiredTotal, 0);
    }
};