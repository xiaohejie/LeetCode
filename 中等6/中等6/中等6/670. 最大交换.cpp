#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
	670. ��󽻻�
        ����������������ͬ����������Ҫ������(���������������)
        ʹ��̰�Ĳ���
*/
class Solution {
public:
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int n = charArray.size();
        int maxIdx = n - 1;
        int idx1 = -1, idx2 = -1;
        for (int i = n - 1; i >= 0; i--) {
            //���������ң��ҵ��������±�Ҳ�����ַ�
            if (charArray[i] > charArray[maxIdx]) {
                maxIdx = i;
            }
            else if (charArray[i] < charArray[maxIdx]) {
                //�ҵ������ֵС���ַ�
                idx1 = i;
                idx2 = maxIdx;
            }
        }
        if (idx1 >= 0) {
            swap(charArray[idx1], charArray[idx2]);
            return stoi(charArray);
        }
        else {
            return num;
        }
    }
};

//���������
class Solution {
public:
    int maximumSwap(int num) {
        vector<pair<int, int>> vec;
        string str = to_string(num);
        int count = 0;
        while (num) {
            int n = num % 10;
            vec.push_back({ count, n });
            num /= 10;
            count++;
        }
        //�ҵ�����
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
                if (a.second > b.second) {
                    return true;
                }
                else if (a.second == b.second) {
                    return a.first < b.first;
                }
                return false;
            });
        //�ҵ����ģ���������ͬ���ģ����ҳ��±���С��
        int val = vec[0].first;
        int index = vec[0].second;
        swap(str[0], str[index]);
        return stoi(str);
    }
};