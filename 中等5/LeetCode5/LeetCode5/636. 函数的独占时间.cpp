#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
	636. 函数的独占时间
        使用栈模拟
*/
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st;       //{index，开始运行时间}
        vector<int> res(n, 0);
        for (auto log : logs) {
            char type[10];
            int index, timestamp;
            sscanf(log.c_str(), "%d:%[^:]:%d", &index, type , &timestamp);      //将字符串进行拆分
            //进行判断时start还是end
            if (type[0] == 's') {//如果是start
                //如果栈中非空
                if (!st.empty()) {
                    //将栈顶元素暂停，并更新res中元素运行的时间
                    res[st.top().first] += timestamp - st.top().second;
                    st.top().second = timestamp;
                }
                //不管栈中是否为空，都需要将该元素放入栈中
                st.push({index, timestamp});
            }
            else {//是end
                //取出栈顶元素
                auto s = st.top();
                st.pop();
                res[s.first] += timestamp - s.second + 1;
                if (!st.empty())
                {
                    st.top().second = timestamp + 1;
                }
            }
        }
    }
};