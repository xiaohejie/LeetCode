#include<iostream>
#include<unordered_set>
#include<stdlib.h> 
#include<time.h> 
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
//unordered_set���ܽ���������unordered_set�У�Ԫ�ص�ֵͬʱҲ��Ψһ��ʶ���ļ���
//���ǲ��ɱ�ģ���ˣ�unordered_set�е�Ԫ���������в��ܱ��޸ģ��������ǿ��Ա������ɾ����
int main11() {
	unordered_set<int> set;
	srand(time(nullptr));//�������������
	for (int i = 0; i < 10; i++) {
		set.insert(rand() % 100);
	}
	//sort(set.begin(), set.end(),cmp);
	for (auto& num : set) {
		cout << num << " ";
	}
	return 0;
}