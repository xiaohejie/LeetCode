#include<iostream>
#include <vector>
using namespace std;
/*
	ʹ�û������ڣ�
*/
int helper(int arr[], int k, vector<pair<int, int>> ans) {
	int sum = 0;
	int length = 0;
	int maxLen = 0;
	for (int i = 0; i < 9; i++) {
		//�ӵ�һ���ַ���ʼ����
		sum += arr[i];
		length++;
		if (sum <= k) {
			//ֱ�Ӽ���ans
			ans.push_back(make_pair(sum, length));
		}
		else {
			//sum > k
			length--;
			sum -= arr[i - length];
			ans.push_back(make_pair(sum, length));
		}
	}
	for (int i = 0; i < 9; i++) {
		cout << ans[i].second << " ";
		if (ans[i].first <= k) {
			maxLen = max(maxLen, ans[i].second);
		}
	}
	cout << endl; 
	return maxLen;
}
int main() {
	int arr[] = { 1,1,1,9, 9, 1, 1,1,1 };
	int k = 4;
	vector<pair<int, int>> ans;
	cout << helper(arr, k, ans) << endl;
	
	return 0;
}