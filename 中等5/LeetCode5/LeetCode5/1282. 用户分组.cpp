#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	1282. 用户分组
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> map;
        int len = groupSizes.size();
        for (int i = 0; i < len; i++) {
            int count = groupSizes[i];      //确定该数所在组
            map[count].push_back(i);        //将该数放入个数组
        }
        /*for (auto m : map) {
            cout << m.first << "：";
            for (int i = 0; i < m.second.size(); i++) {
                cout << m.second[i] << " ";
            }
            cout << endl;
        }*/
        //逐个遍历map
        for (auto& m : map) {
            int groupSize = m.first;
            auto groupNum = m.second;
            if (groupSize >= groupNum.size()) {
                //使用一个数组就可以全部放进去
                ans.push_back(groupNum);
            }
            else {
                int i = groupNum.size() / groupSize, j = groupNum.size() % groupSize;
                vector<int> res;
                for (int ii = 0; ii < i; ii++) {
                    for (int m = 0; m < groupSize; m++) {
                        res.push_back(groupNum[m+ ii * groupSize]);
                    }
                    ans.push_back(res);
                    res.clear();
                }
                if (j != 0) {
                    vector<int> res;
                    for (int jj = i * groupSize; jj < groupNum.size(); jj++) {
                        res.push_back(groupNum[jj]);
                    }
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};

/*
    1422. 分割字符串的最大得分
*/
class Solution {
public:
    int maxScore(string s) {
        int score = 0;
        int n = s.size();
        if (s[0] == '0') {
            score++;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                score++;
            }
        }
        int ans = score;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '0') {
                score++;
            }
            else {
                score--;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};