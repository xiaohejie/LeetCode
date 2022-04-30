#include<iostream>
#include<vector>
using namespace std;
/*
	单词搜索：（和太平洋大西洋水流问题类似）
		从第一个单词开始遍历搜索，如果左边不行，则进行转弯（上，下）遍历
*/
class Solution {
private:
	int m = 0;
	int n = 0;
	vector<pair<int, int>> directions{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
public:
	bool helper(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int i, int j, int index) {//index表示搜索到第几个数
		if (board[i][j] != word[index]) {
			return false;		//如果当前数不等，则返回false
		}
		else if (index == word.length() - 1) {
			return true;		//如果搜索到最后一个单词，并且相等，说明已经找到
		}
		//下面是相等，但没有到达最后一个字符
		visited[i][j] = true;		//记录当前位置已经访问过
		bool result = false;		//记录是否存在该单词
		//上下左右进行遍历，并且要是没有访问过的单词
		for (auto& dir : directions) {
			int newI = i + dir.first, newJ = j + dir.second;
			//判断未超过边界
			if (newI >= 0 && newI < m && newJ >= 0 && newJ < n) {
				//并且该单词没有访问过
				if (visited[newI][newJ] == false) {
					bool flag = helper(board, visited, word, newI, newJ, index + 1);
					if (flag) {
						return true;
					}
				}
			}
		}
		//判断到最后要将该字符重置为未访问过
		visited[i][j] = false;
		return result;
	}
    bool exist(vector<vector<char>>& board, string word) {
		m = board.size();
		n = board[0].size();
		vector<vector<int>> visited(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				bool flag = helper(board, visited, word, i, j, 0);
				if (flag) {
					return true;
				}
			}
		}
		return false;
    }
};