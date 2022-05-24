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
    //maxChoosableInteger：可选择的最大数；desiredTotal：谁先达到该值；usedNumbers：已经使用过的数；currentTotal：目前的和
    bool backTrack(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal) {
   //这里usedNumbers比较难理解，因为使用的二进制表示，因为maxChoosableInteger最多只有20位
      //usedNumbers | (1 << i)
        //如果memo中没有该usedNumbers
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