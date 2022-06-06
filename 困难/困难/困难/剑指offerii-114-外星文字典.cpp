#include<iostream>
#include<unordered_map>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
/*
	�������ֵ䣺
		
*/
class Solution {
public:
	string alienOrder(vector<string>& words) {
		vector<int> hasAlpha(26, 0);		//��¼26���ַ��Ƿ���û�г��ֵ�
		int len = words.size();
		//�ж�26���ַ���Щû���֣���Щ������
		for (auto& word : words) {
			for (auto& ch : word) {
				hasAlpha[ch - 'a'] = 1;
			}
		}

		/*Ԥ����*/
		//map�����洢key���������Щ�ַ�
		unordered_map<char, vector<char>> map;
		int counter = 0;
		vector<int> indegree(26, 0);	//���
		for (int i = 0; i < len - 1; i++) {
			string  curWord = words[i];
			string nextWord = words[i + 1];

			/*ע���ж�*/
			if (curWord.size() > nextWord.size() && curWord.find(nextWord) == 0) {
				return "";
			}

			int minSize = min(curWord.size(), nextWord.size());
			for (int j = 0; j < minSize; j++) {
				if (curWord[j] != nextWord[j]) {
					//�����ǰ�ַ����ĵ�j���ַ���������һ���ַ����ĵ�j���ַ�����˵���ڵ�ǰ�ַ��ĺ���
					map[curWord[j]].push_back(nextWord[j]);
					indegree[nextWord[j] - 'a']++;		//��¼���
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
			//���Ϊ0���Ž�ȥ
			//cout << indegree[i] << "-" << hasAlpha[i] << "  ";
			if (indegree[i] == 0 && hasAlpha[i]) {
				myQueue.push_back((char)(i + 'a'));
			}
		}

		vector<bool> hasHad(26, false);		//��¼��Щ�ַ��Ѿ��Ž�ȥ
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
					//�жϵ�ǰ�ڵ����Щ�ڵ�÷Ž�ȥ
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