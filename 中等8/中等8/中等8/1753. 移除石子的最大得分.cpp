#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	1753. 移除石子的最大得分
    贪心算法：每次将两个最大的数进行减小
*/
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> vec{ a, b, c };
        sort(vec.begin(), vec.end());
        int ans = 0;
        while (vec[1] != 0 && vec[0] != 0) {
            ans++;
            vec[1]--, vec[2]--;
            sort(vec.begin(), vec.end());
        }
        return ans;
    }
};