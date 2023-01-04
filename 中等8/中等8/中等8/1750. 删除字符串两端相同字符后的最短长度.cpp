#include<iostream>
using namespace std;
/*
	1750. 删除字符串两端相同字符后的最短长度
*/
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right && s[left] == s[right]) {
            char c = s[left];
            while (left <= right && s[left] == c) {
                left++;
            }
            while (left <= right && s[right] == c) {
                right--;
            }
        }
        return right - left + 1;
    }
};