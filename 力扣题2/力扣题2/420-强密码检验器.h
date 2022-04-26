#pragma once
#include<iostream>
using namespace std;
/*
	强密码检验器：
		如果一个密码满足下述所有条件，则认为这个密码是强密码：
		由至少 6 个，至多 20 个字符组成。
		至少包含 一个小写 字母，一个大写 字母，和 一个数字 。
		同一字符 不能 连续出现三次 (比如 "...aaa..." 是不允许的, 但是 "...aa...a..." 如果满足其他条件也可以算是强密码)。
		给你一个字符串 password ，返回 将 password 修改到满足强密码条件需要的最少修改步数。
		如果 password 已经是强密码，则返回 0 。

	在一步修改操作中，你可以：
		插入一个字符到 password ，
		从 password 中删除一个字符，或
		用另一个字符来替换 password 中的某个字符。
*/
class Solution420 {
public:
	int strongPasswordChecker(string password) {
		int num = 0;
		bool isNUM = false, isA = false, isa = false;
		if (password.size() >= 6 && password.size() <= 20) {
			//进行下一步检查
			for (int i = 0; i < password.size(); ++i) {
				if (password[i] <= '9' && password[i] >= '0') {
					//数字
					isNUM = true;
				}
				else if (password[i] <= 'z' && password[i] >= 'a') {
					isa = true;
				}
				else if(password[i] <= 'Z' && password[i] >= 'A') {
					isA = true;
				}
			}
			if (isNUM && isA && isa) {
				//判断是否包含至少包含 一个小写 字母，一个大写 字母，和 一个数字 
				//进行下一次判断
				for (int i = 1; i < password.size() - 1; ++i) {
					if (password[i] == password[i + 1] && password[i - 1] == password[i]) {
						//连续三个数相同
					}
				}
			}
			else {
				//判断缺少什么元素，对num进行增加
			}
		}
	}
};
