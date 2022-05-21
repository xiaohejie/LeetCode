#include<iostream>
#include<vector>
using namespace std;
/*
	��Ծ��ϷII��
		ʹ������̰�ģ�ͦ����⣩����Ҫ���ǵ�ǰ���ţ�ҲҪ������һ������
*/
class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int curMax = 0, nextMax = 0;//curMax��ָ��ǰ�ܹ�������Զ���룬nextMax��ָ��ǰ������һ���ܹ�������Զ����
		int step = 0;		//���ٲ�
		/*
		* ����LeetCode��⣩
			�ڱ�������ʱ�����ǲ��������һ��Ԫ�أ�������Ϊ�ڷ������һ��Ԫ��֮ǰ��
			���ǵı߽�һ�����ڵ������һ��λ�ã�������޷��������һ��λ���ˡ�
			����������һ��Ԫ�أ��ڱ߽�����Ϊ���һ��λ�õ�����£����ǻ�����һ�Ρ�����Ҫ����Ծ��������
			������ǲ��ط������һ��Ԫ�ء�
		*/
		for (int i = 0; i < n - 1; i++) {		//����Ϊʲô��n-1��̫������Ϊ��Ŀ�м������ǿ��Ե������һ��λ�ã�
			if (i + nums[i] > nextMax) {
				//����nextMax
				nextMax = i + nums[i];
			}
			if (i == curMax) {
				//��i�ߵ�curMaxʱ���ͱ������
				step++;
				curMax = nextMax;	
			}
		}
		return step;
	}
};