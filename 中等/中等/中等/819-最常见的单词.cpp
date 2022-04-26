#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
/*
	最常见的单词：
		给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。
		题目保证至少有一个词不在禁用列表中，而且答案唯一。
		禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。
	思路：
		用set表示banned中的单词
		用map表示单词出现的个数
		遍历paragraph中的单词
		{
			如果是字符{
				将其小写放入word中
			}如果不是字符，且word的长度大于0（表示前面是一个单词）{
				如果banned中没有该单词{
					map记录单词出现的个数
					并与maxDanci进行比较
				}
				word=""
			}
		}
		遍历结束后，遍历map{
			找出与max个数相同的单词
		}

*/
class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_set<string> set;
		//用map表示禁忌单词，便于查找
		for (auto& s : banned) {
			set.emplace(s);
		}
		unordered_map<string, int>map;
		int len = paragraph.size();
		int maxCount = 0;
		string word = "";
		//遍历para
		for (int i = 0; i <= len; i++) {
			//加=是为了最后一个单词
			if (i < len && isalpha(paragraph[i])) {
				word.push_back(tolower(paragraph[i]));
			}
			else if(word.size() > 0){
				if (!set.count(word)) {
					map[word]++;
					maxCount = max(maxCount, map[word]);
				}
				word = "";
			}
		}
		for (auto& n : map) {
			cout << n.first << "：" << n.second << endl;
		}
		string res = "";
		for (auto& [word, num] : map) {
			if (maxCount == num) {
				res = word;
				break;
			}
		}
		return res;
	}
};