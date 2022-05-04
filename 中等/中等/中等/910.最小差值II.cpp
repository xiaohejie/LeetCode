#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	��С��ֵ��
		����+ö�ٷָ��
		������ѡ���� i ��һ�㡰��һ������ʱ��Ҳ���� A[0] ~ A[i] ��Ԫ�ض����ƣ�
			A[i + 1] ~ A[A.length - 1] ��Ԫ�ض����ơ���ʱ B ���ֵ�� A[i] + K��D ���ֵ�� A[A.length - 1] - K��
			����������ֵҪô�� B ��Ҫô�� D �㣬Ҳ����˵����������ֵ�� Max(A[i] + K, A[A.length - 1] - K)��
		ͬ��������ʱ A ���ֵ�� A[0] + K��C ���ֵ�� A[i + 1] - K��
			���������СֵҪô�� A ��Ҫô�� C �㣬Ҳ����˵���������Сֵ�� Min(A[0] + K, A[i + 1] - K)��

		��ˣ���Ŀ��Ҫ�ġ�����������ֵ����Сֵ�Ĳ�ֵ����
		���� Max(A[i] + K, A[A.length - 1] - K) - Min(A[0] + K, A[i + 1] - K)��
		K ��ֵ����Ŀ�����Ĺ̶�ֵ�������������������������ʽ�Ľ��������С�Ļ�����Ҫ���ı� i ��ֵ��
		Ҳ����˼������Ҫ���������һ������������ǰ�������һ�����п��ܵ� i ��ֵ��Ȼ��ȡ������ʽ����Сֵ���ɡ�

*/
class Solution {
public:
	int smallestRangeII(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), Max, Min;
		int d = nums[n - 1] - nums[0];		//����ֵ
		for (int i = 1; i < n; i++) {
			Max = max(nums[n - 1] - k, nums[i - 1] + k);
			Min = min(nums[0] + k, nums[i] - k);
			d = min(Max-Min, d);
		}
		return d;
	}
};