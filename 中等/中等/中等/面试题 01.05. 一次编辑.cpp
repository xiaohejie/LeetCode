#include<iostream>
using namespace std;
/*
	一次编辑：
		
*/
class Solution {
public:
	bool oneEditAway(string first, string second) {
		int len1 = first.length();
		int len2 = second.length();
		//如果长度相差大于2，则直接返回false
		if (len1 == len2) {
			//判断相等的情况下，能不能通过替换，使他们相等
			int count = 0;
			for (int i = 0; i < len1; i++) {
				if (first[i] != second[i]) {
					count++;		//记录字符串中不相等的字符
					if (count > 1) {
						return false;
					}
				}
			}
			return true;
		}
		else if ((len1-len2) == 1) {
			//first长度大于second，长度相差1的情况下，能不能通过插入或删除一个字符
			int i = 0, j = 0;
			while (i < len1 && j < len2) {
				if (first[i] == second[j]) {
					i++;
					j++;
				}
				else {
					i++;
				}
				if (i - j >= 2) {
					return false;
				}
			}
			return true;
		}
		else if ((len2-len1) == 1) {
			//first长度小于second，长度相差1的情况下，能不能通过插入或删除一个字符
			int i = 0, j = 0;
			while (i < len1 && j < len2) {
				if (first[i] == second[j]) {
					i++;
					j++;
				}
				else {
					j++;
				}
				if (j - i >= 2) {
					return false;
				}
			}
			return true;
		}
		return false;
	}
};