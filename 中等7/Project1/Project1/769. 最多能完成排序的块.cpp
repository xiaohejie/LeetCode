#include<iostream>
#include<vector>
using namespace std;
/*
	769. ������������Ŀ�
        ���ҳ�0���ڵ�λ��index
        �ҳ��±�0~index����������num
        {
            ��num >= index{  return 1;}
            ����
            count++;
            ����index
            ����Ѱ��num + 1�����֣����бȽ�
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




//�÷�������
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
        //�ҳ�0ǰ�������������ֵ
        int maxNum = findMax(arr, end, start);
        //��������ֵ�������±�index��ֱ�ӷ���1
        if (maxNum != end) {
            count = 1;
            return;
        }
        //����index
        count++;
        start = end + 1;
        if (start >= arr.size()) {
            return;
        }
        int nextNum = end + 1;
        end = find(arr, nextNum);       //�ҳ�nextNum���±�
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