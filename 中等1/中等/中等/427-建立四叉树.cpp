#include<iostream>
#include<vector>
using namespace std;
/*
	建立四叉树：
		采用DFS进行遍历

*/
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
class Solution {
public:
    Node* DFS(vector<vector<int>>& grid, int x0, int y0, int x1, int y1) {
        for (int i = 0; i < x1; i++) {
            for (int j = 0; j < y1; j++) {
                if (grid[x0][y0] != grid[i][j]) {
                    //如果grid中有两个数不相等
                    return new Node(1, false,
                        DFS(grid, x0, y0, (x0 + x1) / 2, (y0 + y1) / 2),
                        DFS(grid, x0, (y0 + y1) / 2, (x0 + x1) / 2, y1),
                        DFS(grid, (x0 + x1) / 2, y0, x1, (y0 + y1) / 2),
                        DFS(grid, (x0 + x1) / 2, (y0 + y1) / 2, x1, y1)
                    );
                }
            }
        }
        //否则的话，grid全部相等
        return new Node(grid[0][0], true);
    }
    Node* construct(vector<vector<int>>& grid) {
        return DFS(grid, 0, 0, grid.size(), grid[0].size());
    }
};