#include<iostream>
#include<vector>
using namespace std;
/*
	769. 最多能完成排序的块
        先找出0所在的位置index
        找出下标0~index中最大的数字num
        {
            若num >= index{  return 1;}
            否则，
            count++;
            更新index
            继续寻找num + 1的数字，进行比较
        }
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            m = max(m, arr[i]);
            if (m == i) {
                res++;
            }
        }
        return res;
    }
};




//该方法不行
class Solution {
    int find(vector<int>& arr, int num) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == num) {
                return i;
            }
        }
        return -1;
    }
    int findMax(vector<int>& arr, int index, int start) {
        int maxN = 0;
        for (int i = start; i <= index; i++) {
            maxN = max(maxN, arr[i]);
        }
        return maxN;
    }
public:
    void helper(vector<int>& arr, int start, int end, int count) {
        //找出0前面所有数的最大值
        int maxNum = findMax(arr, end, start);
        //如果该最大值不等于下标index，直接返回1
        if (maxNum != end) {
            count = 1;
            return;
        }
        //更新index
        count++;
        start = end + 1;
        if (start >= arr.size()) {
            return;
        }
        int nextNum = end + 1;
        end = find(arr, nextNum);       //找出nextNum的下标
        helper(arr, start, end, count);
    }
    int maxChunksToSorted(vector<int>& arr) {
        int len = arr.size();
        int count = 0;
        int index = find(arr, 0);
        helper(arr, 0, index, count);
        return count;
    }
};