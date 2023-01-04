#include<iostream>
using namespace std;
//int main() {
//
//	int i;
//	int arr[15] = { 9,6,11,3,5,12,8,7,10,15,14,4,1,13,2 };//初始化数组
//
//	//gap的初始大小是3x+1
//	for (int gap = 4; gap > 0; gap /= 2) {//定义一个空隙为4，依次减倍
//		for (i = gap; i < 15; i++) {
//			for (int j = i; j > gap - 1; j -= gap) {
//				//从第0个数开始，每隔4个数进行两两比较
//				if (arr[j - gap] > arr[j]) {
//					int temp = arr[j - gap];
//					arr[j - gap] = arr[j];
//					arr[j] = temp;//插到前面来（交换值）
//				}
//			}
//		}
//	}
//
//	for (int j = 0; j < 15; j++)//打印数组
//	{
//		cout << arr[j] << endl;
//	}
//	system("pause");
//	return 0;
//}
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;//gap折半
		int i = 0;
		//进行一趟排序
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
int main8() {
	int arr[15] = { 9,6,11,3,5,12,8,7,10,15,14,4,1,13,2 };//初始化数组
	ShellSort(arr, 15);
	for (int j = 0; j < 15; j++)//打印数组
	{
		cout << arr[j] << endl;
	}
	return 0;
}