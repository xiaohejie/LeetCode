#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
	670. 最大交换
        找最大的数，若有相同的最大的数就要找最靠后的(这个方法有无问题)
        使用贪心策略
*/
class Solution {
public:
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int n = charArray.size();
        int maxIdx = n - 1;
        int idx1 = -1, idx2 = -1;
        for (int i = n - 1; i >= 0; i--) {
            //从右往左找，找到最大的且下标也最大的字符
            if (charArray[i] > charArray[maxIdx]) {
                maxIdx = i;
            }
            else if (charArray[i] < charArray[maxIdx]) {
                //找到比最大值小的字符
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

//这个有问题
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
        //找到最大的
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
                if (a.second > b.second) {
                    return true;
                }
                else if (a.second == b.second) {
                    return a.first < b.first;
                }
                return false;
            });
        //找到最大的，若存在相同最大的，则找出下标最小的
        int val = vec[0].first;
        int index = vec[0].second;
        swap(str[0], str[index]);
        return stoi(str);
    }
};