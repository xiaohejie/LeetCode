#include<iostream>
#include<vector>
using namespace std;
/*
	788. 旋转数字
*/
class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        vector<int> v1{2, 5, 6, 9};
        vector<int> v2{0, 1, 8};
        for (int i = 1; i <= n; i++) {
            if (i < 10) {
                if (find(v1.begin(), v1.end(), i) != v1.end()) {
                    //说明找到旋转数字
                    count++;
                }
            }
            else {
                //说明是两个以上的数字，需要进行判断：至少含有一个v1中的数字，其余的必须要是v2中的
                vector<int> v;
                int num = i;
                while (num) {
                    v.push_back(num % 10);
                    num /= 10;
                }
                int count1 = 0, count2 = 0; 
                for (int j = 0; j < v.size(); j++) {
                    if (find(v1.begin(), v1.end(), v[j]) != v1.end()) {
                        count1++;
                    }
                    else if (find(v2.begin(), v2.end(), v[j]) != v2.end()) {
                        count2++;
                    }
                }
                if (count1 != 0 && count1 + count2 == v.size()) {
                    count++;
                }
            }
        }
        return count;
    }
};