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
			����Ҫע��һ��ϸ�ڣ����� for ѭ���У�i < nums.length - 1������ĩβ��
			��Ϊ��ʼ��ʱ��߽��ǵ� 00 ��λ�ã�steps �Ѿ��� 11 �ˡ�
			����ͼ��������һ���պ�������ĩβ����ʱ steps ��ʵ���ü� 11 �ˡ�
			����� i < nums.length��i ����������ʱ�򣬻���� if ����У�steps ���� 11��
		*/
		for (int i = 0; i < n - 1; i++) {		//����Ϊʲô��n-1��̫������LeetCode���	��������
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