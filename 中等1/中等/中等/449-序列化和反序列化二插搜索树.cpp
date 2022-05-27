#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
	序列化和反序列化搜索二叉树：
		    
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

	// Encodes a tree to a single string.
	//先序遍历
	void helper1(TreeNode* root, vector<int>& res) {
		if (root == nullptr) {
			return;
		}
		res.push_back(root->val);
		helper1(root->left, res);
		helper1(root->right, res);
	}
	string vectorToString(vector<int>& res) {
		string ans = "";
		//res中为空的话直接返回答案；
		if (res.empty()) {
			return ans;
		}
		for (int i = 0; i < res.size() - 1; i++) {
			ans += to_string(res[i]) + ",";
		}
		ans += to_string(res[res.size() - 1]);		//最后一个字符后面不需要将“,”，所以最后加上
		return ans;
	}
	string serialize(TreeNode* root) {
		vector<int> res;
		helper1(root, res);					//进行先序遍历
		return vectorToString(res);			//然后将数组转化为字符串进行输出
	}

	// Decodes your encoded data to tree.
	//将字符串进行拆解
	vector<int> split(string& s) {
		vector<int> res;
		int pos = 0;
		string token;
		while ((pos = s.find(",")) != string::npos) {		//string::npos：表示字符串的末尾
			token = s.substr(0, pos);
			res.push_back(atoi(token.c_str()));		//stoi：是转化为int型
			s.erase(0, pos + 1);
		}
		res.push_back(atoi(s.c_str()));
		return res;
	}
	TreeNode* deserialize(string data) {
		if (data.empty()) {
			return nullptr;
		}
		vector<int> res = split(data);		//对字符串进行分割（上面有定义）
		TreeNode* newNode = new TreeNode(res[0]);
		vector<int> leftVals;
		vector<int> rightVals;
		for (int num : res) {
			if (num < res[0]) {
				//放入左子树
				leftVals.push_back(num);
			}
			else if (num > res[0]) {
				//放入右子树
				rightVals.push_back(num);
			}
		}
		//然后进行递归
		newNode->left = deserialize(vectorToString(leftVals));
		newNode->right = deserialize(vectorToString(rightVals));
		return newNode;
	}
};