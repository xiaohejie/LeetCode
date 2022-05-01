#include<iostream>
#include <vector>
using namespace std;
/*
	388-文件的最长绝对路径：
		用栈模拟DFS的过程：
			如果当前字符是正常字符{
				这里还需要判断cnt(\t的个数)是否小于v.size(){
					小于的话要进行出栈
				}

				加入temp；
				并判断是否是文件（是否含有‘.’）
			}else if(当前字符是'\n'){
			
			}else if(当前字符是‘\t’){
			
			}

*/
class Solution {
public:
	int lengthLongestPath(string input) {
		input += '\n';		//最后加如\n因为只有最后是\n才会将最后文件加进去
		vector<string> v;
		string temp = "";	//用来存字符串（文件名或目录名）
		bool isFile = false;
		int ans = 0;
		int curLen = 0;		//当前文件或文件夹的长度
		int cnt = 0;		//用于存\t的数量
		for (int i = 0; i < input.size(); i++) {
			//判断当前字符是什么
			if (isalpha(input[i]) || input[i] == '.' || isdigit(input[i] || input[i] == ' ')) {
				while (cnt < v.size()) {
					//这里搞不懂（画图理解，别忘了后面还有置0）
					curLen -= v.back().size();
					v.pop_back();
				}

				temp += input[i];
				if (input[i] == '.') {
					//表明当前是一个文件
					isFile = true;
				}
			}
			else if (input[i] == '\n') {
				//表示已访问到当前文件或文件夹的结尾，可以放入栈中
				v.push_back(temp);
				curLen += temp.size();		//更新目前的长度
				if (isFile) {
					//如果是文件，就要进行最大值判断
					int size = v.size() - 1;		//因为绝对路径每个文件后面会加/
					ans = max(ans, curLen + size);
				}
				//判断完成之后需要进行更新
				isFile = false;
				temp = "";
				cnt = 0;		//这里搞不懂
			}
			else if (input[i] == '\t') {
				//计算\t的数量
				cnt++;

			}
		}
		return ans;
	}
};