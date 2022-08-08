#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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


/*
    1260. ��ά����Ǩ��
*/
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int index = (i * n + j + k) % (m * n);
                ans[index / n][index % n] = grid[i][j];
            }
        }
        return ans;
    }
};


/*
    1184. ����վ��ľ���
*/
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0, sum1 = 0, sum2 = 0;
        int n = distance.size();
        if (start > destination) {
            swap(start, destination);
        }
        //˳ʱ��
        for (int i = start; i < destination; i++) {
            sum1 += distance[i];
        }
        //��ʱ��
        for (int i = 0; i < n - (destination - start); i++) {
            sum2 += distance[(destination + i) % n];
        }
        return min(sum1, sum2);
    }
};

/*
    1331. �������ת��
*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans, vec;
        unordered_map<int, int> map;
        vec = arr;
        sort(vec.begin(), vec.end());
        int idx = 1;
        for (int i = 0; i < arr.size()-1; i++) {
            //���ж�map������û��vec[i]
            if (!map.count(vec[i])) {
                map[vec[i]] = idx;
                idx++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(map[arr[i]]);
        }
        return ans;
    }
};

/*
    1374. ����ÿ���ַ��������������ַ���
*/
class Solution {
public:
    string generateTheString(int n) {
        if (n % 2 == 1) {
            return string(n, 'a');
        }
        return string(n - 1, 'a') + 'b';
    }
};

/*
    1408. �����е��ַ���ƥ��
*/
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++ ) {
                if (j != i && words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};