#include<iostream>
using namespace std;
/*
	777. 在LR字符串中交换相邻字符
        双指针
*/
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n && j < n) {
            //跳过字符串中的“X”
            while (i < n && start[i] == 'X') {
                i++;
            }
            while (j < n && end[j] == 'X') {
                j++;
            }
            //比较
            if (i < n && j < n) {
                if (start[i] != end[j]) {
                    return false;
                }
                char c = start[i];
                //规则不符合，c等于L时，i>j，反之亦然
                if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
        }
        //比较到最后，剩余的字符必须全部是X；
        while (i < n) {
            if (start[i] != 'X') {
                return false;
            }
            i++;
        }
        while (j < n) {
            if (end[j] != 'X') {
                return false;
            }
            j++;
        }
        return true;
    }
};
