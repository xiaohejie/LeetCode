#include<iostream>
using namespace std;
//int main() {
//
//	int i;
//	int arr[15] = { 9,6,11,3,5,12,8,7,10,15,14,4,1,13,2 };//��ʼ������
//
//	//gap�ĳ�ʼ��С��3x+1
//	for (int gap = 4; gap > 0; gap /= 2) {//����һ����϶Ϊ4�����μ���
//		for (i = gap; i < 15; i++) {
//			for (int j = i; j > gap - 1; j -= gap) {
//				//�ӵ�0������ʼ��ÿ��4�������������Ƚ�
//				if (arr[j - gap] > arr[j]) {
//					int temp = arr[j - gap];
//					arr[j - gap] = arr[j];
//					arr[j] = temp;//�嵽ǰ����������ֵ��
//				}
//			}
//		}
//	}
//
//	for (int j = 0; j < 15; j++)//��ӡ����
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
		gap = gap / 2;//gap�۰�
		int i = 0;
		//����һ������
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
	int arr[15] = { 9,6,11,3,5,12,8,7,10,15,14,4,1,13,2 };//��ʼ������
	ShellSort(arr, 15);
	for (int j = 0; j < 15; j++)//��ӡ����
	{
		cout << arr[j] << endl;
	}
	return 0;
}