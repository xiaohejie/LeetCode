#include<iostream>
#include<vector>
/*
	位运算：
		先找出最高位；
		如果最高位不同的话{
			直接返回0；
		}
		int result；
		然后从最高位开始{
			int i = 该位是1还是0
			int j = 该位是1还是0
			if(i ！= j){
				return result;
			}
			if(该位为1){
				result在该位置1
			}
		}
*/
using namespace std;
//找出最高位
int msb(int n) {
	int count = 0;
	while(n){
		count++;
		n = n >> 1;
	}
	return count - 1;
}
//get到msb为的值
int getBit(int n, int msb) {
	return (n >> msb) & 1;
}
//置1运算
int setBit(int n, int msb) {
	return ((1 << msb) | n);
}
//进行位运算
int rangeBitwiseAnd(int n, int m) {
	int msb1 = msb(n);
	int msb2 = msb(m);
	if (msb1 != msb2) {
		return 0;
	}
	int msb = msb1;
	int result = 0;
	while (msb>=0) {
		//get到msb为的值
		int i = getBit(n, msb);
		int j = getBit(m, msb);
		if (i != j) {
			return result;
		}
		else if(i == 1) {
			//将第msb为置位1
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