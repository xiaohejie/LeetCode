#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
	636. �����Ķ�ռʱ��
        ʹ��ջģ��
*/
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st;       //{index����ʼ����ʱ��}
        vector<int> res(n, 0);
        for (auto log : logs) {
            char type[10];
            int index, timestamp;
            sscanf(log.c_str(), "%d:%[^:]:%d", &index, type , &timestamp);      //���ַ������в��
            //�����ж�ʱstart����end
            if (type[0] == 's') {//�����start
                //���ջ�зǿ�
                if (!st.empty()) {
                    //��ջ��Ԫ����ͣ��������res��Ԫ�����е�ʱ��
                    res[st.top().first] += timestamp - st.top().second;
                    st.top().second = timestamp;
                }
                //����ջ���Ƿ�Ϊ�գ�����Ҫ����Ԫ�ط���ջ��
                st.push({index, timestamp});
            }
            else {//��end
                //ȡ��ջ��Ԫ��
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