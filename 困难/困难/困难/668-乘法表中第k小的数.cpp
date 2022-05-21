#include<iostream>
using namespace std;
/*
	�˷����е�kС��������378����������е� K С��Ԫ�����ƣ���
		ʹ�ö��ַ�����
*/
class Solution {
public:
	//���ڼ������λ��С���ж��ٸ�����
	int count(int m, int n, int mid) {
		int i = m, j = 1;
		int count = 0;
		while (i >= 1 && j <= n) {
			if (i * j <= mid) {
				count += i;
				j++;
			}
			else {
				i--;
			}
		}
		return count;
	}
	int findKthNumber(int m, int n, int k) {
		int left = 1, right = m * n;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (count(m, n , mid) < k) {
				//����ȵ�ǰ��λ��С�ĸ���С��k����˵����kС�����ֻ�����λ�����棬��λ����Ҫ���ϼ�
				left = mid + 1;
			}
			else {
				//��֮��˵������kС����������λ����ǰ�棬��λ����Ҫ��
				right = mid;
			}
		}
		return left;
	}
};