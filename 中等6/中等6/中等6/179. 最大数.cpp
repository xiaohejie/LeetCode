#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
	179. 最大数
*/

class Solution {
private:
    static bool cmp(const int& a, const int& b) {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), cmp);
        for (int& t : nums) {
            ans += to_string(t);
        }
        if (ans[0] == '0') {  // 不能是00000
            return "0";
        }
        return ans;
    }
};

//哪里有问题
class Solution {
    static bool cmp(const string& s1, const string& s2) {
        int len = min(s1.length(), s2.length());
        for (int i = 0; i < len; i++) {
            if (s1[i] - '0' > s2[i] - '0') {
                return true;
            }
            else if (s1[i] - '0' < s2[i] - '0') {
                return false;
            }
        }
        //若前面数字都一样，就判断，长的字符串后面的数字是否大于len
        string s;
        if (s1.length() > len) {
            s = s1;
        }
        else {
            s = s2;
        }
        if (s[len - 1] > s[len]) {
            return false;
        }
        return true;
    }
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> strs;
        for (int i = 0; i < nums.size(); i++) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), cmp);
        for (auto& str: strs) {
            ans += str;
        }
        return ans;
    }
};