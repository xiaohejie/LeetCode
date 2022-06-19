#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
/*
	1037. ��Ч�Ļ����ڣ�
        ����һ�������㣬�������������ͬ�Ҳ���һ��ֱ����
        ����б�ʽ��бȽϣ�
*/

class Solution1037 {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        return (y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1);
    }
};

/*
    1051. �߶ȼ����
*/
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> heightPre = heights;
        sort(heights.begin(), heights.end(), greater<int>());
        //�Ƚ���Щ����һ��
        for (int i = 0; i < heights.size(); i++) {
            if (heightPre[i] != heights[i]) {
                count++;
            }
        }
        return count;
    }
};

/*
    1089. ��д��
*/
class Solution {
public:
    void helper(vector<int>& arr, int idx) {
        int len = arr.size();
        for (int i = len - 1; i > idx; i--) {
            arr[i] = arr[i - 1];
        }
    }
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                helper(arr, i);
                i++;
            }
        }
    }
};