#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	最小差值：
		排序+枚举分割点
		当我们选择在 i 这一点“切一刀”的时候，也就是 A[0] ~ A[i] 的元素都上移，
			A[i + 1] ~ A[A.length - 1] 的元素都下移。此时 B 点的值是 A[i] + K，D 点的值是 A[A.length - 1] - K。
			新数组的最大值要么是 B 点要么是 D 点，也就是说新数组的最大值是 Max(A[i] + K, A[A.length - 1] - K)。
		同样道理，此时 A 点的值是 A[0] + K，C 点的值是 A[i + 1] - K。
			新数组的最小值要么是 A 点要么是 C 点，也就是说新数组的最小值是 Min(A[0] + K, A[i + 1] - K)。

		因此，题目需要的“新数组的最大值和最小值的差值”，
		就是 Max(A[i] + K, A[A.length - 1] - K) - Min(A[0] + K, A[i + 1] - K)。
		K 的值是题目给出的固定值，因此如果我们想让上面这个算式的结果尽可能小的话，就要靠改变 i 的值，
		也就是思考究竟要在哪里“切这一刀”。因此我们挨个遍历一下所有可能的 i 的值，然后取上面算式的最小值即可。

*/
class Solution {
public:
	int smallestRangeII(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), Max, Min;
		int d = nums[n - 1] - nums[0];		//最大差值
		for (int i = 1; i < n; i++) {
			Max = max(nums[n - 1] - k, nums[i - 1] + k);
			Min = min(nums[0] + k, nums[i] - k);
			d = min(Max-Min, d);
		}
		return d;
	}
};