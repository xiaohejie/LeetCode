#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
/*
	1161. 最大层内元素和
        //使用广度优先搜索
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = INT_MIN;
        unordered_map<int, int> map;
        queue<TreeNode*> q;
        q.push(root);
        int index = 1;
        while (!q.empty()) {
            int count = q.size();
            int sum = 0;
            while (count--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans = max(ans, sum);
            if (map.find(sum) == map.end()) {
                map[sum] = index;
            }
            index++;
        }
        return map[ans];
    }
};