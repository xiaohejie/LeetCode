#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
	���л��ͷ����л�������������
		    
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
	//�������
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
		//res��Ϊ�յĻ�ֱ�ӷ��ش𰸣�
		if (res.empty()) {
			return ans;
		}
		for (int i = 0; i < res.size() - 1; i++) {
			ans += to_string(res[i]) + ",";
		}
		ans += to_string(res[res.size() - 1]);		//���һ���ַ����治��Ҫ����,��������������
		return ans;
	}
	string serialize(TreeNode* root) {
		vector<int> res;
		helper1(root, res);					//�����������
		return vectorToString(res);			//Ȼ������ת��Ϊ�ַ����������
	}

	// Decodes your encoded data to tree.
	//���ַ������в��
	vector<int> split(string& s) {
		vector<int> res;
		int pos = 0;
		string token;
		while ((pos = s.find(",")) != string::npos) {		//string::npos����ʾ�ַ�����ĩβ
			token = s.substr(0, pos);
			res.push_back(atoi(token.c_str()));		//stoi����ת��Ϊint��
			s.erase(0, pos + 1);
		}
		res.push_back(atoi(s.c_str()));
		return res;
	}
	TreeNode* deserialize(string data) {
		if (data.empty()) {
			return nullptr;
		}
		vector<int> res = split(data);		//���ַ������зָ�����ж��壩
		TreeNode* newNode = new TreeNode(res[0]);
		vector<int> leftVals;
		vector<int> rightVals;
		for (int num : res) {
			if (num < res[0]) {
				//����������
				leftVals.push_back(num);
			}
			else if (num > res[0]) {
				//����������
				rightVals.push_back(num);
			}
		}
		//Ȼ����еݹ�
		newNode->left = deserialize(vectorToString(leftVals));
		newNode->right = deserialize(vectorToString(rightVals));
		return newNode;
	}
};