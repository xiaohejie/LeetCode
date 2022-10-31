#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
	面试题 01.02. 判定是否互为字符重排
*/
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        unordered_map<int, int> map1(26, 0), map2(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (map1[i] != map2[i]) { 
                return false;
            }
        }
        return true;
    }
};
/*
    面试题 01.09. 字符串轮转
*/
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        int len = s1.length();
        for (int i = 0; i < len; i++) {
            if (s1[0] == s2[i]) {
                string s = s2.substr(i, len - i) + s2.substr(0, i);
                if (s == s1) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
    1694. 重新格式化电话号码
*/
class Solution {
public:
    string reformatNumber(string number) {
        string digits;
        for (char ch : number) {
            if (isdigit(ch)) {
                digits.push_back(ch);
            }
        }

        int n = digits.size();
        int pt = 0;
        string ans;
        while (n) {
            if (n > 4) {
                ans += digits.substr(pt, 3) + "-";
                pt += 3;
                n -= 3;
            }
            else {
                if (n == 4) {
                    ans += digits.substr(pt, 2) + "-" + digits.substr(pt + 2, 2);
                }
                else {
                    ans += digits.substr(pt, n);
                }
                break;
            }
        }
        return ans;
    }
};

/*
    1784. 检查二进制字符串字段
*/
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};

/*
    1800. 最大升序子数组和
*/
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int index = 0;
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            if (nums[i] <= nums[i-1]) {
                //计算前面的数的和
                int sum = 0;
                for (int j = index; j < i; j++) {
                    sum += nums[j];
                }
                ans = max(ans, sum);
                index = i;
            }
            else {
                continue;
            }
        }
        int sum = 0;
        for (int i = index; i < len; i++) {
            sum += nums[i];
        }
        ans = max(ans, sum);
        return ans;
    }
};

/*
    1790. 仅执行一次字符串交换能否使两个字符串相等
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        int count = 0;
        vector<char> v;
        if (len1 != len2) {
            return false;
        }
        for (int i = 0; i < len1; i++) {
            if (s1[i] != s2[i]) {
                count++;
                v.push_back(s1[i]);
                v.push_back(s2[i]);
            }
            if (count > 2) {
                return false;
            }
        }
        if (count == 0) {
            return true;
        }
        if (count == 1) {
            return false;
        }
        if (v[0] != v[3] || v[1] != v[2]) {
            return false;
        }
        return true;
    }
};

/*
   1700. 无法吃午餐的学生数量 
*/
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        //累加，即1的总数
        int s1 = accumulate(students.begin(), students.end(), 0);
        int s0 = students.size() - s1;
        for (int i = 0; i < students.size(); i++) {
            if (sandwiches[i] == 0 && s0 > 0) {
                s0--;
            }
            else if(sandwiches[i] == 1 && s1 > 0){
                s1--;
            }
            else {
                break;
            }
        }
        return s0 + s1;
    }
};
