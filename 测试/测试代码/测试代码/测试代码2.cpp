#include<iostream>
using namespace std;
int main2() {
	int i;
	int arr[10];//��ʼ������

	for (i = 0; i < 10; i++)
	{
		cin >> arr[i];//����10Ҫ�������
	}

	for (int i = 0; i < 10; i++) {//һ��ѭ��10��
		for (int j = i + 1; j < 10; j++) {//�ҵ�10�������е���Сֵ
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;//����ֵ
			}
		}
	}
	for (int j = 0; j < 10; j++)//��ӡ����
	{
		cout << arr[j] << endl;
	}
	system("pause");
	return 0;
}