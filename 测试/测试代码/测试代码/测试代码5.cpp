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
    void dfs(string s, int n, int index, int start) {
        if (start == n && index == 4) {
            string res = to_string(cur[0]);
            for (int i = 1; i < 4; i++) {
                res += "." + to_string(cur[i]);
            }
            ans.push_back(res);
            return;
        }
        for (int i = start, num = 0; i < n; i++) {
            num = num * 10 + s[i] - '0';
            cout << num << " ";
            if (num > 255) {
                break;
            }
            cur.push_back(num);
            dfs(s, n, index + 1, i + 1);
            cur.pop_back();
            if (num == 0) {
                break;
            }
        }
        cout << endl;
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if (n < 4) {
            return ans;
        }
        dfs(s, n, 0, 0);
        return ans;
    }
};

int main() {
    string s = "3552";
    Solution so;
    vector<string> ans = so.restoreIpAddresses(s);
    for (auto a : ans) {
        cout << s << endl;
    }
    return 0;
}