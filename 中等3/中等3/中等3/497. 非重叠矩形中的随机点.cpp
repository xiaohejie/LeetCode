#include<iostream>
#include<vector>
#include <random>
using namespace std;
/*
	497. ���ص������е������
*/
class Solution {
    vector<int> arr;
    vector<vector<int>>& rects;
public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        this->arr.push_back(0);
        //�õ�ÿ���������ж��ٸ��㣬�ֱ��ǴӼ�����
        for (auto& rect : rects) {
            this->arr.push_back(arr.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        }
    }

    vector<int> pick() {
        //������������λ�ã���0��arr.back() - 1��
        int k = rand() % arr.back() + 1;
        int left = 0, right = rects.size();
        //ʹ�ö��ַ����ҵ�������rects�е�λ��
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= k) right = mid;
            else left = mid + 1;
        }
        //����ҵ��������������ɾ����еĵ�
        vector<int> target = rects[right - 1];
        int x = target[2] - target[0] + 1;
        int y = target[3] - target[1] + 1;
        return { rand() % x + target[0], rand() % y + target[1] };
    }
};