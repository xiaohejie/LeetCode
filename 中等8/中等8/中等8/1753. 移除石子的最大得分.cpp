#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	1753. �Ƴ�ʯ�ӵ����÷�
    ̰���㷨��ÿ�ν��������������м�С
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