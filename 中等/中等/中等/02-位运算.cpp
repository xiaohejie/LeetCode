
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
		//如果最高位不一样，则直接返回0
		return 0;
	}
	//记录相同的最高位
	int msb = msb1;
	//输出结果
	int result = 0;
	while (msb>=0) {
		//get到msb位的值，是0还是1
		int i = getBit(n, msb);
		int j = getBit(m, msb);
		if (i != j) {
			//如果i和j不一样的话，就直接返回result，因为，后面都是0
			return result;
		}
		else if(i == 1) {
			//如果该位一样并且是1，就将result的第msb为置位1
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