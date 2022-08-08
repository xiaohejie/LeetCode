#include<iostream>
using namespace std;
int main2() {
	int i;
	int arr[10];//初始化数组

	for (i = 0; i < 10; i++)
	{
		cin >> arr[i];//输入10要排序的数
	}

	for (int i = 0; i < 10; i++) {//一共循环10次
		for (int j = i + 1; j < 10; j++) {//找到10个数当中的最小值
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;//交换值
			}
		}
	}
	for (int j = 0; j < 10; j++)//打印数组
	{
		cout << arr[j] << endl;
	}
	system("pause");
	return 0;
}