#include<iostream>
#include<unordered_map>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
/*
	外星文字典：
		
*/
class Solution {
public:
	string alienOrder(vector<string>& words) {
		vector<int> hasAlpha(26, 0);		//记录26个字符是否有没有出现的
		int len = words.size();
		//判断26个字符那些没出现，那些出现了
		for (auto& word : words) {
			for (auto& ch : word) {
				hasAlpha[ch - 'a'] = 1;
			}
		}

		/*预处理*/
		//map用来存储key后面跟了那些字符
		unordered_map<char, vector<char>> map;
		int counter = 0;
		vector<int> indegree(26, 0);	//入度
		for (int i = 0; i < len - 1; i++) {
			string  curWord = words[i];
			string nextWord = words[i + 1];

			/*注意判断*/
			if (curWord.size() > nextWord.size() && curWord.find(nextWord) == 0) {
				return "";
			}

			int minSize = min(curWord.size(), nextWord.size());
			for (int j = 0; j < minSize; j++) {
				if (curWord[j] != nextWord[j]) {
					//如果当前字符串的第j个字符不等于下一个字符串的第j个字符，就说明在当前字符的后面
					map[curWord[j]].push_back(nextWord[j]);
					indegree[nextWord[j] - 'a']++;		//记录入度
					//cout << indegree[nextWord[j] - 'a'] << " ";
					break;
				}
			}
		}
		counter = count_if(hasAlpha.begin(), hasAlpha.end(), [](int i) {return i != 0; });
		cout << counter << endl;

		/**/
		deque<char> myQueue;
		for (int i = 0; i < 26; i++) {
			//入度为0，放进去
			//cout << indegree[i] << "-" << hasAlpha[i] << "  ";
			if (indegree[i] == 0 && hasAlpha[i]) {
				myQueue.push_back((char)(i + 'a'));
			}
		}

		vector<bool> hasHad(26, false);		//记录哪些字符已经放进去
		string res;
		while (!myQueue.empty())
		{
			int size = myQueue.size();
			for (int i = 0; i < size; i++) {
				char curChar = myQueue.front();
				myQueue.pop_front();
				res.push_back(curChar);
				hasHad[curChar - 'a'] = true;

				for (auto& nextChar : map[curChar]) {
					indegree[nextChar - 'a']--;
					//判断当前节点后哪些节点该放进去
					if (indegree[nextChar - 'a'] == 0 && !hasHad[nextChar - 'a']) {
						hasHad[nextChar - 'a'] = true;
						myQueue.push_back(nextChar);
					}
				}
			}
		}
		cout << res.size() << endl;
		cout << res << endl;
		return counter != res.size() ? "" : res;
	}
};