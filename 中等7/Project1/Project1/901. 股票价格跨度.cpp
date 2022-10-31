#include<iostream>
#include<stack>
using namespace std;
/*
	901. ��Ʊ�۸���
        ʹ�õ���ջ
*/
class StockSpanner {
public:
    StockSpanner() {
        //�±��ջ���г�ʼ��
        this->index = -1;
        this->st.emplace(this->index, INT_MAX);
    }

    int next(int price) {
        index++;        //��¼�ü۸���±�
        while (price >= st.top().second) {//����۸����ջ���ļ۸񣬾�һֱ����ջ��Ԫ��
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