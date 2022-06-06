#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/* 961. �ڳ��� 2N ���������ҳ��ظ� N �ε�Ԫ�� */
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

/*434. �ַ����еĵ�����*/
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

/*965. ��ֵ������*/
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

/*1022. �Ӹ���Ҷ�Ķ�������֮��*/
class Solution {
public:
    //����ÿ���ڵ�
    int helper(TreeNode* root, vector<int>& vec, int i) {
        if (root == nullptr) {
            return 0;
        }
        i = (i << 1) | root->val;       //����ֱ��ת����ʮ�������Ѿ�
        if (root->left == nullptr && root->right == nullptr) {
            vec.push_back(i);
            return i;
        }
        else {
            return helper(root->left, vec, i) + helper(root->right, vec, i);
        }

    }
    /*int toTen(int num) {
        int res = 0;
        while () {

        }
    }*/
    int sumRootToLeaf(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return  root->val;
        }
        vector<int> vec;        //�����洢ÿ���ڵ�
        int res = helper(root, vec, 0);
        for (auto& num : vec) {
            cout << num << "  ";
        }
        return res;
    }
};