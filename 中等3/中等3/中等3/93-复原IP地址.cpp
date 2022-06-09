#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	93-复原IP地址
        使用回溯法
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
        //判断中止条件
        if (idx == 4 && start == s.length()) {
            //表示当前是成功的IP地址
            string str = to_string(cur[0]);
            ans.push_back(str);
            for (int i = 1; i < cur.size(); i++) {
                str += "." + to_string(cur[i]);
            }
            ans.push_back(str);
            return;
        }

        for (int i = start, num = 0; i < s.length(); i++) {
            num = num*10 + s[i] - '0';     //得到当前数字
            if (num > 255) {
                break;      //如果当前数字大于255，就不和规范
            }
            cout << num << "  ";
            cur.push_back(num);
            dfs(s, idx + 1, i + 1);     //进行递归
            cur.pop_back();                 //回溯
            if (num == 0) {
                break;              //因为不能含有前导0
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