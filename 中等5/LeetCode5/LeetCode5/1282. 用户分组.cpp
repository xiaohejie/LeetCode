#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	1282. �û�����
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> map;
        int len = groupSizes.size();
        for (int i = 0; i < len; i++) {
            int count = groupSizes[i];      //ȷ������������
            map[count].push_back(i);        //���������������
        }
        /*for (auto m : map) {
            cout << m.first << "��";
            for (int i = 0; i < m.second.size(); i++) {
                cout << m.second[i] << " ";
            }
            cout << endl;
        }*/
        //�������map
        for (auto& m : map) {
            int groupSize = m.first;
            auto groupNum = m.second;
            if (groupSize >= groupNum.size()) {
                //ʹ��һ������Ϳ���ȫ���Ž�ȥ
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
    1422. �ָ��ַ��������÷�
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