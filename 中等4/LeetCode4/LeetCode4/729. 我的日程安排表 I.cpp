#include<iostream>
#include<set>
using namespace std;
/*
	729. 我的日程安排表 I
*/
class MyCalendar {
    set<pair<int, int>> booked;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        //使用二分法查找起点大于等于end的第一个区间
        auto it = booked.lower_bound({end, 0});
        //进行判断(判断该数是否小于预定的第一个或者该书的前一个的end小于等于start)
        if (it == booked.begin() || (--it)->second <= start) {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};
