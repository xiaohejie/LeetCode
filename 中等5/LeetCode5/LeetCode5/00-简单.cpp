#include<iostream>
#include<vector>
using namespace std;
/*
	��ָ Offer II 041. �������ڵ�ƽ��ֵ
*/

class MovingAverage {
    int len = 0;
    vector<int> ans;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        len = size;
    }

    double next(int val) {
        ans.push_back(val);
        float sum = 0;
        if (ans.size() < len) {
            for (auto& a : ans) {
                sum += a;
            }
            return sum / ans.size();
        }
        else {
            float sum = 0;
            //�����size��ֵ
            for (int i = ans.size() - 1, j = 0; j < len; j++, i--) {
                sum += ans[i];
            }
            return sum / len;
        }
    }
};