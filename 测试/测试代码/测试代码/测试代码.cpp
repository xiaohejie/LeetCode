#include<iostream>
#include <vector>
#include<string>
#include<numeric>
#include<algorithm>
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

/*
	473. 火柴拼正方形(自己再稍微画个图)
*/
class Solution {
public:
	//edges：记录四条边       edge：正方形实际应有的长度     index：用到第几根火柴
	bool backtrack(vector<int>& matchsticks, vector<int>& edges, int edge, int index) {
		//判断终止条件
		if (index == matchsticks.size()) {
			return true;
		}

		//遍历四条边
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i] + matchsticks[index] > edge) {
				//如果当前长度加上diindex根火柴的长度大于边长
				continue;       //尝试下一个桶
			}
			edges[i] += matchsticks[index];     //第index根火柴放入第i个桶中
			cout << edges[i] << " ";
			if (backtrack(matchsticks, edges, edge, index + 1)) {   //递归的放置下一根火柴
				return true;            // 下一根火柴放置成功就直接返回true
			}
			//回溯
			edges[i] -= matchsticks[index];     //将第index根火柴从桶i中拿出
		}
		return false;           //如果第index根火柴无法放入任何一个桶，就返回false
	}
	bool makesquare(vector<int>& matchsticks) {
		//求和，如果不是4的倍数
		int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (sum % 4 != 0) {
			return false;
		}
		int edge = sum / 4;     //边长
		vector<int> edges(4);   //正方形的4条边    
		//排序(从大到小)
		//sort(matchsticks.begin(), matchsticks.end(), greater<int>());
		//回溯
		return backtrack(matchsticks, edges, edge, 0);
	}
};

int main() {
	vector<int> matchsticks = { 1, 1, 2, 2, 2 };
	Solution s;
	s.makesquare(matchsticks);





	///*
	//int arr[] = { 1,1,1,9, 9, 1, 1,1,1 };
	//int k = 4;
	//vector<pair<int, int>> ans;
	//cout << helper(arr, k, ans) << endl;*/

	///*stoi和atoi的使用*/
	//string s1 = "2147772", s2 = "-214748";
	//string s3 = "214748666666663", s4 = "-21474836488";
	//cout << stoi(s1) << endl;
	//cout << stoi(s2) << endl;
	//cout << atoi(s3.c_str()) << endl;
	//cout << atoi(s4.c_str()) << endl;	//atoi()的参数是const char *,因此对于字符串str我们必须调用c_str()的方法把这个string 转换成const char *类型的；
	//cout << stoi(s1, 0, 8) << endl;		//将字符串 str 从 0 位置开始到末尾的 8 进制转换为十进制

	return 0;
}