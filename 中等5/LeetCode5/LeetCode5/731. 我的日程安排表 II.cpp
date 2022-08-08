#include<iostream>
#include<unordered_map>
using namespace std;
/*
	731. 我的日程安排表 II
        使用线段树
*/
class MyCalendarTwo {
private:
    unordered_map<int, pair<int, int>> tree;
public:
    MyCalendarTwo() {

    }
    void update(int start, int end, int val, int l, int r, int idx) {
        if (l > end || r < start) {
            //该线段树范围内没有
            return;
        }
        if (start <= l && end >= r) {
            //完整包含该区间
            tree[idx].first += val;     //最值
            tree[idx].second += val;    //懒惰值
        }
        else {
            //没有完整包含，就去寻找子树
            int mid = (l + r) >> 1;
            update(start, end, val, l, mid, idx*2);         //左子线段树
            update(start, end, val, mid+1, r, idx*2+1);     //右子线段树
            //更新父线段树的最值
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }
    bool book(int start, int end) {
        update(start, end-1, 1, 0, 1e9, 1);
        if (tree[1].first > 2) {
            //撤销更新
            update(start, end-1, -1, 0, 1e9, 1);
            return false;
        }
        return true;
    }
};