#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	93-��ԭIP��ַ
        ʹ�û��ݷ�
*/
class Solution {
    vector<string> ans;
    vector<int> cur;
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if (len < 4) {
            return ans;
        }
        dfs(s, 0, 0);
        return ans;
    }
    void dfs(string s, int idx, int start) {
        //�ж���ֹ����
        if (idx == 4 && start == s.length()) {
            //��ʾ��ǰ�ǳɹ���IP��ַ
            string str = to_string(cur[0]);
            ans.push_back(str);
            for (int i = 1; i < cur.size(); i++) {
                str += "." + to_string(cur[i]);
            }
            ans.push_back(str);
            return;
        }

        for (int i = start, num = 0; i < s.length(); i++) {
            num = num*10 + s[i] - '0';     //�õ���ǰ����
            if (num > 255) {
                break;      //�����ǰ���ִ���255���Ͳ��͹淶
            }
            cout << num << "  ";
            cur.push_back(num);
            dfs(s, idx + 1, i + 1);     //���еݹ�
            cur.pop_back();                 //����
            if (num == 0) {
                break;              //��Ϊ���ܺ���ǰ��0
            }
        }
    }
};

int main() {
    string str = "25525511135";
    Solution s;
    s.restoreIpAddresses(str);
    return 0;
}