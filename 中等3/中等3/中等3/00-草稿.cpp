#include<iostream>
#include<vector>
using namespace std;
/*
	1037. 有效的回旋镖：
        定义一组三个点，这三个点各不相同且不再一条直线上
        （用斜率进行比较）
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1);
    }
};