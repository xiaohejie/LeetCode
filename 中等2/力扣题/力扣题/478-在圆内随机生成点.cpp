#include<iostream>
#include<vector>
#include <random>
using namespace std;
/*
	478-在圆内随机生成点
*/
class Solution {
private:
    mt19937 gen{ random_device{}() };
    uniform_real_distribution<double> dis;      //生成随机数（在构造函数中给定范围）
    double xc, yc, r;

public:
    Solution(double radius, double x_center, double y_center)
        : dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}

    vector<double> randPoint() {
        while (true) {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= r * r) {
                return { xc + x, yc + y };
            }
        }
    }
};