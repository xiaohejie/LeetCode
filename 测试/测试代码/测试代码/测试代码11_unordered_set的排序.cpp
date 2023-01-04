#include<iostream>
#include<unordered_set>
#include<stdlib.h> 
#include<time.h> 
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
//unordered_set不能进行排序，在unordered_set中，元素的值同时也是唯一标识它的键。
//键是不可变的，因此，unordered_set中的元素在容器中不能被修改，但是它们可以被插入和删除。
int main11() {
	unordered_set<int> set;
	srand(time(nullptr));//设置随机数种子
	for (int i = 0; i < 10; i++) {
		set.insert(rand() % 100);
	}
	//sort(set.begin(), set.end(),cmp);
	for (auto& num : set) {
		cout << num << " ";
	}
	return 0;
}