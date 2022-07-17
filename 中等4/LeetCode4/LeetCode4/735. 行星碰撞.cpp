#include<iostream>
#include<vector>
using namespace std;
/*
	735. 行星碰撞
        模拟栈
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int len = asteroids.size();
        //使用模拟栈操作
        /*正向行驶的行星放入栈，逆向行驶的与站里面的元素进行比较*/
        for (int i = 0; i < len; i++) {
            bool isBoom = 1;        //记录行星是否爆炸
            while (asteroids[i] < 0 && isBoom && !ans.empty() && ans.back() > 0) {
                isBoom = (asteroids[i] + ans.back() < 0);       //判断相等的时候(两个行星都要除去)
                if (asteroids[i] + ans.back() <= 0) {
                    ans.pop_back();
                }
            }
            if (isBoom) {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }










    //这段代码有问题
    /*
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int len = asteroids.size();
        vector<int> isBoom(len, 1);
        for (int i = 0; i < len; i++) {
            if (asteroids[i] > 0 && isBoom[i]) {
                //向右移动
                for (int j = i+1; j < len; j++) {
                    //大于0或者该行星已经不存在
                    if (asteroids[j] > 0 || isBoom[j] == 0) {
                        continue;
                    }
                    else {
                        //小于0，要进行相撞
                        if (asteroids[i] > abs(asteroids[j])) {
                            isBoom[j] = 0;
                        }
                        else if (asteroids[i] < abs(asteroids[j])) {
                            isBoom[i] = 0;
                            //并且跳出循环
                            break;
                        }
                        else{
                            isBoom[i] = 0;
                            isBoom[j] = 0;
                            break;
                        }
                    }
                }
            }
            else if (asteroids[i] < 0 && isBoom[i]) {
                for (int j = i - 1; j >= 0; j--) {
                    //小于0或者该行星已经不存在
                    if (asteroids[j] < 0 || isBoom[j] == 0) {
                        continue;
                    }
                    else {
                        //大于0，要进行相撞
                        if (abs(asteroids[i]) > abs(asteroids[j])) {
                            isBoom[j] = 0;
                        }
                        else if (abs(asteroids[i]) < abs(asteroids[j])) {
                            isBoom[i] = 0;
                            //并且跳出循环
                            break;
                        }
                        else {
                            isBoom[i] = 0;
                            isBoom[j] = 0;
                            break;
                        }
                    }
                }
            }
        }
        //判断
        for (int i = 0; i < len; i++) {
            if (isBoom[i]) {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }*/
};