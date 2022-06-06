#include<iostream>
#include <vector>
#include<string>
using namespace std;
/*
	使用滑动窗口：
*/
int helper(int arr[], int k, vector<pair<int, int>> ans) {
	int sum = 0;
	int length = 0;
	int maxLen = 0;
	for (int i = 0; i < 9; i++) {
		//从第一个字符开始遍历
		sum += arr[i];
		length++;
		if (sum <= k) {
			//直接加入ans
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

	/*stoi和atoi的使用*/
	string s1 = "2147772", s2 = "-214748";
	string s3 = "214748666666663", s4 = "-21474836488";
	cout << stoi(s1) << endl;
	cout << stoi(s2) << endl;
	cout << atoi(s3.c_str()) << endl;
	cout << atoi(s4.c_str()) << endl;	//atoi()的参数是const char *,因此对于字符串str我们必须调用c_str()的方法把这个string 转换成const char *类型的；
	cout << stoi(s1, 0, 8) << endl;		//将字符串 str 从 0 位置开始到末尾的 8 进制转换为十进制

	return 0;
}