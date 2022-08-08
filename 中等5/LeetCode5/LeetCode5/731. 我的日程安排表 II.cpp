#include<iostream>
#include<unordered_map>
using namespace std;
/*
	731. �ҵ��ճ̰��ű� II
        ʹ���߶���
*/
class MyCalendarTwo {
private:
    unordered_map<int, pair<int, int>> tree;
public:
    MyCalendarTwo() {

    }
    void update(int start, int end, int val, int l, int r, int idx) {
        if (l > end || r < start) {
            //���߶�����Χ��û��
            return;
        }
        if (start <= l && end >= r) {
            //��������������
            tree[idx].first += val;     //��ֵ
            tree[idx].second += val;    //����ֵ
        }
        else {
            //û��������������ȥѰ������
            int mid = (l + r) >> 1;
            update(start, end, val, l, mid, idx*2);         //�����߶���
            update(start, end, val, mid+1, r, idx*2+1);     //�����߶���
            //���¸��߶�������ֵ
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }
    bool book(int start, int end) {
        update(start, end-1, 1, 0, 1e9, 1);
        if (tree[1].first > 2) {
            //��������
            update(start, end-1, -1, 0, 1e9, 1);
            return false;
        }
        return true;
    }
};