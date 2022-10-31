#include<iostream>
#include<stack>
using namespace std;
/*
	901. 股票价格跨度
        使用单调栈
*/
class StockSpanner {
public:
    StockSpanner() {
        //下标和栈进行初始化
        this->index = -1;
        this->st.emplace(this->index, INT_MAX);
    }

    int next(int price) {
        index++;        //记录该价格的下标
        while (price >= st.top().second) {//如果价格大于栈顶的价格，就一直弹出栈顶元素
            st.pop();
        }
        int ret = index - st.top().first;
        st.emplace(index, price);
        return ret;
    }
private:
    stack<pair<int, int>> st;
    int index;
};