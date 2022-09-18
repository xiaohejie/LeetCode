#include<iostream>
using namespace std;
/*
	165. �Ƚϰ汾��
        �и��ַ������Ƚ�ÿ���汾�ţ����ܽ����а汾�ź���һ�𣩣�������'.'�и��ַ������ֱ���бȽϣ�
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.length(), n = version2.length();
        int i = 0, j = 0;
        while (i < m || j < n) {
            int sum1 = 0;
            for (; i < m && version1[i] != '.'; i++) {
                sum1 = sum1 * 10 + (version1[i] - '0');
            }
            i++;
            int sum2 = 0;
            for (; j < n && version2[j] != '.'; j++) {
                sum2 = sum2 * 10 + (version2[j] - '0');
            }
            j++;
            if (sum1 > sum2) {
                return 1;
            }
            else if (sum1 < sum2) {
                return -1;
            }
        }
        return 0;
    }
};