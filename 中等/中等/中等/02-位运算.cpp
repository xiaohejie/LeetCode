#include<iostream>
#include<vector>
/*
	λ���㣺
		���ҳ����λ��
		������λ��ͬ�Ļ�{
			ֱ�ӷ���0��
		}
		int result��
		Ȼ������λ��ʼ{
			int i = ��λ��1����0
			int j = ��λ��1����0
			if(i ��= j){
				return result;
			}
			if(��λΪ1){
				result�ڸ�λ��1
			}
		}
*/
using namespace std;
//�ҳ����λ
int msb(int n) {
	int count = 0;
	while(n){
		count++;
		n = n >> 1;
	}
	return count - 1;
}
//get��msbΪ��ֵ
int getBit(int n, int msb) {
	return (n >> msb) & 1;
}
//��1����
int setBit(int n, int msb) {
	return ((1 << msb) | n);
}
//����λ����
int rangeBitwiseAnd(int n, int m) {
	int msb1 = msb(n);
	int msb2 = msb(m);
	if (msb1 != msb2) {
		return 0;
	}
	int msb = msb1;
	int result = 0;
	while (msb>=0) {
		//get��msbΪ��ֵ
		int i = getBit(n, msb);
		int j = getBit(m, msb);
		if (i != j) {
			return result;
		}
		else if(i == 1) {
			//����msbΪ��λ1
			result = setBit(result, msb);
		}
		msb--;
	}
	return result;
}
int main02() {
	//cout << msb(8) << endl;
	cout << rangeBitwiseAnd(2, 2) << endl;
	return 0;
}