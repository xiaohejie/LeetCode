#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	646. �����������435�����ص��������ƣ�
		��̬�滮��̰��
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
		//ʹ��̰��
		int cur = INT_MIN, res = 0;
		//������������ķ�ʽ���������Щ��ͬ����Ҫע��һ�£�
		sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
			return a[1] < b[1];
			});
		for (auto& p : pairs) {
			if (cur < p[0]) {
				cur = p[1];
				res++;
				cout << p[0] << " " << p[1] << endl;
			}
		}
		return res;
    }
};
class SolutionDP {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		//ʹ�ö�̬�滮����̫���ף�
		int n = pairs.size();
		sort(pairs.begin(), pairs.end());
		//������̬����
		vector<int> dp(n, 1);
		//״̬ת�Ʒ���
		for (int i = 0; i < n; i++) {
			//����j����ѭ����ԭ���ǣ�dp[j]�Ĳ��ǵ����ģ�����Ҫ��0��ʼ������dp[j]��һ��С��dp[j+1]��
			for (int j = 0; j < i; j++) {
				if (pairs[j][1] < pairs[i][0]) {
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
		return dp[n - 1];
	}
};