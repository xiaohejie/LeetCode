#include<iostream>
#include<vector>
using namespace std;
/*
	788. ��ת����
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
                    //˵���ҵ���ת����
                    count++;
                }
            }
            else {
                //˵�����������ϵ����֣���Ҫ�����жϣ����ٺ���һ��v1�е����֣�����ı���Ҫ��v2�е�
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