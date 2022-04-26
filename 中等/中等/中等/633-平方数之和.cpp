#include <iostream>
using namespace std;
/*
	平方数之和：
        给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

    思路：
        先对该数进行sqrt开方：int n = sqrt(num);
        int i = 1, j = n;
        while(i < j){
            int sum = i *i + j * j;
            if(sum == c){
                return true;
            }
            if(sum < c){
                //如果sum < c
                i++;
            }else{
                //sum > c
                j--;
            }
            return false;
        }
*/
class Solution {
public:
    bool judgeSquareSum(int c) {

    }
};