#include<iostream>
#include<set>
using namespace std;
/*
	729. �ҵ��ճ̰��ű� I
*/
class MyCalendar {
    set<pair<int, int>> booked;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        //ʹ�ö��ַ����������ڵ���end�ĵ�һ������
        auto it = booked.lower_bound({end, 0});
        //�����ж�(�жϸ����Ƿ�С��Ԥ���ĵ�һ�����߸����ǰһ����endС�ڵ���start)
        if (it == booked.begin() || (--it)->second <= start) {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};
