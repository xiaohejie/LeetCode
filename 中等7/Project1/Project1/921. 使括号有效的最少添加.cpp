#include<iostream>
using namespace std;
/*
	921. ʹ������Ч���������
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int len = s.size();
        int leftCount = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                leftCount++;
            }
            else {
                //����Ļ�����������
                if (leftCount > 0) {
                    //�ж�ǰ���Ƿ���������
                    leftCount--;
                }
                else {
                    ans++;
                }
            }
        }
        //���ʣ���ٸ������ţ���˵��Ҫ������ٸ�������
        ans += leftCount;
        return ans;
    }
};