#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
/*
	����ĵ��ʣ�
		����һ������ (paragraph) ��һ�����õ����б� (banned)�����س��ִ�����࣬ͬʱ���ڽ����б��еĵ��ʡ�
		��Ŀ��֤������һ���ʲ��ڽ����б��У����Ҵ�Ψһ��
		�����б��еĵ�����Сд��ĸ��ʾ�����������š������еĵ��ʲ����ִ�Сд���𰸶���Сд��ĸ��
	˼·��
		��set��ʾbanned�еĵ���
		��map��ʾ���ʳ��ֵĸ���
		����paragraph�еĵ���
		{
			������ַ�{
				����Сд����word��
			}��������ַ�����word�ĳ��ȴ���0����ʾǰ����һ�����ʣ�{
				���banned��û�иõ���{
					map��¼���ʳ��ֵĸ���
					����maxDanci���бȽ�
				}
				word=""
			}
		}
		���������󣬱���map{
			�ҳ���max������ͬ�ĵ���
		}

*/
class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_set<string> set;
		//��map��ʾ���ɵ��ʣ����ڲ���
		for (auto& s : banned) {
			set.emplace(s);
		}
		unordered_map<string, int>map;
		int len = paragraph.size();
		int maxCount = 0;
		string word = "";
		//����para
		for (int i = 0; i <= len; i++) {
			//��=��Ϊ�����һ������
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
			cout << n.first << "��" << n.second << endl;
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