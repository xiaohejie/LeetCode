#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/* 961. 在长度 2N 的数组中找出重复 N 次的元素 */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto& num : nums) {
            map[num]++;
        }
        for (auto& m : map) {
            if (m.second == nums.size() / 2) {
                return m.first;
            }
        }   
        return NULL;
    }
};

/*434. 字符串中的单词数*/
class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        s += ' ';
        for (int i = 1; i < s.size(); i++)
            if (s[i] == ' ' && s[i - 1] != ' ') ans++;
        return ans;
    }
};

/*965. 单值二叉树*/
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
    void helper(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        nums.push_back(root->val);
        helper(root->left, nums);
        helper(root->right, nums);
    }
    bool isUnivalTree(TreeNode* root) {
        vector<int> nums;
        helper(root, nums);
        for (auto& num : nums) {
            if (num != nums[0]) {
                return false;
            }
        }
        return true;
    }
};