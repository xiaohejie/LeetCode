#include<iostream>
#include <vector>
#include<string>
#include<numeric>
#include<algorithm>
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

/*
	473. ���ƴ������(�Լ�����΢����ͼ)
*/
class Solution {
public:
	//edges����¼������       edge��������ʵ��Ӧ�еĳ���     index���õ��ڼ������
	bool backtrack(vector<int>& matchsticks, vector<int>& edges, int edge, int index) {
		//�ж���ֹ����
		if (index == matchsticks.size()) {
			return true;
		}

		//����������
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i] + matchsticks[index] > edge) {
				//�����ǰ���ȼ���diindex�����ĳ��ȴ��ڱ߳�
				continue;       //������һ��Ͱ
			}
			edges[i] += matchsticks[index];     //��index���������i��Ͱ��
			cout << edges[i] << " ";
			if (backtrack(matchsticks, edges, edge, index + 1)) {   //�ݹ�ķ�����һ�����
				return true;            // ��һ�������óɹ���ֱ�ӷ���true
			}
			//����
			edges[i] -= matchsticks[index];     //����index������Ͱi���ó�
		}
		return false;           //�����index������޷������κ�һ��Ͱ���ͷ���false
	}
	bool makesquare(vector<int>& matchsticks) {
		//��ͣ��������4�ı���
		int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (sum % 4 != 0) {
			return false;
		}
		int edge = sum / 4;     //�߳�
		vector<int> edges(4);   //�����ε�4����    
		//����(�Ӵ�С)
		//sort(matchsticks.begin(), matchsticks.end(), greater<int>());
		//����
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

	///*stoi��atoi��ʹ��*/
	//string s1 = "2147772", s2 = "-214748";
	//string s3 = "214748666666663", s4 = "-21474836488";
	//cout << stoi(s1) << endl;
	//cout << stoi(s2) << endl;
	//cout << atoi(s3.c_str()) << endl;
	//cout << atoi(s4.c_str()) << endl;	//atoi()�Ĳ�����const char *,��˶����ַ���str���Ǳ������c_str()�ķ��������string ת����const char *���͵ģ�
	//cout << stoi(s1, 0, 8) << endl;		//���ַ��� str �� 0 λ�ÿ�ʼ��ĩβ�� 8 ����ת��Ϊʮ����

	return 0;
}