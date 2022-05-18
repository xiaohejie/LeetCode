#include<iostream>
#include<vector>
using namespace std;
/*
	删除数组中的重复项II：
		
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len <= 2) {
			//如果长度小于等于2，就直接退出
			return len;
		}
		int p = 2;	//从第二个位置开始比较
		for (int i = 2; i < len; i++) {
			//与前一个的前一个进行比较
			if (nums[i] == nums[p-2]) {
			}
			else {
				nums[p] = nums[i];
				p++;
			}
		}
		return p;
	}
};

/*
	          p
	1 1 2 2 3 3 
	          i
*/	