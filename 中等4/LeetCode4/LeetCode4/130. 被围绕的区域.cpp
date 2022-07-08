#include<iostream>
#include<vector>
using namespace std;
/*
	130. 被围绕的区域
*/
class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, int i, int j, char ch) {
        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] == 'X') {
            return;
        }

        //将边界“O”置为“S”
        board[i][j] = ch;
        //进行dfs
        dfs(board, row, col, i-1, j, ch);
        dfs(board, row, col, i + 1, j, ch);
        dfs(board, row, col, i, j - 1, ch);
        dfs(board, row, col, i, j + 1, ch);
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        //处理边界情况
        for (int i = 0; i < row; i++) {
            dfs(board, row, col, i, 0, 'S');
            dfs(board, row, col, i, col - 1, 'S');
        }
        for (int j = 0; j < col; j++) {
            dfs(board, row, col, 0, j, 'S');
            dfs(board, row, col, row - 1, j, 'S');
        }

        //进行遍历
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    dfs(board, row, col, i, j, 'X');
                }
            }
        }
        //恢复边界条件
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'S') {
                    dfs(board, row, col, i, j, 'O');
                }
            }
        }
    }
};