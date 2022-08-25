#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	658. �ҵ� K ����ӽ���Ԫ��
*/
class Solution1 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b) -> bool {
            return abs(a - x) < abs(b - x) || abs(a - x) == abs(b - x) && a < b;
            });
        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
class Solution {
public:
    static bool fun(pair<int, int>a, pair<int, int>b) {
        // return a.second < b.second;
        if (a.second < b.second) {
            return 1;
        }
        else if (a.second == b.second) {
            return a.first < b.first;
        }
        else {
            return 0;
        }
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        vector<pair<int, int>> vec;
        //�����ֵ
        for (int i = 0; i < n; i++) {
            int num = abs(arr[i] - x);
            vec.push_back({arr[i], num});
        }
        //��������
        sort(vec.begin(), vec.end(), fun);
        //���
        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};