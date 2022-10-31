#include<iostream>
using namespace std;
/*
	777. ��LR�ַ����н��������ַ�
        ˫ָ��
*/
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n && j < n) {
            //�����ַ����еġ�X��
            while (i < n && start[i] == 'X') {
                i++;
            }
            while (j < n && end[j] == 'X') {
                j++;
            }
            //�Ƚ�
            if (i < n && j < n) {
                if (start[i] != end[j]) {
                    return false;
                }
                char c = start[i];
                //���򲻷��ϣ�c����Lʱ��i>j����֮��Ȼ
                if ((c == 'L' && i < j) || (c == 'R' && i > j)) {
                    return false;
                }
                i++;
                j++;
            }
        }
        //�Ƚϵ����ʣ����ַ�����ȫ����X��
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
