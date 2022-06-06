#include<iostream>
#include <vector>
#include<string>
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
	/*
	int arr[] = { 1,1,1,9, 9, 1, 1,1,1 };
	int k = 4;
	vector<pair<int, int>> ans;
	cout << helper(arr, k, ans) << endl;*/

	/*stoi��atoi��ʹ��*/
	string s1 = "2147772", s2 = "-214748";
	string s3 = "214748666666663", s4 = "-21474836488";
	cout << stoi(s1) << endl;
	cout << stoi(s2) << endl;
	cout << atoi(s3.c_str()) << endl;
	cout << atoi(s4.c_str()) << endl;	//atoi()�Ĳ�����const char *,��˶����ַ���str���Ǳ������c_str()�ķ��������string ת����const char *���͵ģ�
	cout << stoi(s1, 0, 8) << endl;		//���ַ��� str �� 0 λ�ÿ�ʼ��ĩβ�� 8 ����ת��Ϊʮ����

	return 0;
}