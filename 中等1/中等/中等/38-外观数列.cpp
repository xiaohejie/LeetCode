#include<iostream>
#include<string>
using namespace std;
/*
    外观数列：（使用动态规划）
        当n==1时{
            return “1”；
        }
        string tmp = helper(n-1);       //返回的是前一个shu的结果
        string ans = "";
        char ch = tmp[0];
        //下面计算n的结果
        int n = ans.length();
        int count = 1;      //记录个数
        for(int i = 1; i < n; i++){
            if(tmp[i] == tmp[i-1]){
                //i和i-1相同
                count++;
                continue;
            }
            else{
                //i != i-1，就要更新ans
                ans += to_string(count);
                ans += to_string(ch);
                //更新数据
                ch = tmp[i];
                count = 1;
            }
        }

        
*/
class Solution {
public:
    string helper(int n) {
        if (n == 1) {
            return "1";
        }
        string tmp = helper(n - 1);
        tmp += "a";
        string ans = "";
        char ch = tmp[0];
        int count = 1;
        int len = tmp.size();
        for (int i = 1; i < len; i++) {
            //相同
            if (tmp[i] == tmp[i - 1]) {
                count++;
                continue;
            }
            //不同，更新ans
            ans += to_string(count);
            ans += ch;
            //更新count和ch
            count = 1;
            ch = tmp[i];
        }
        return ans;
    }
    string countAndSay(int n) {
        //法2：递归
        return helper(n);



        //法一：
        /*string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string cur = "";
            int start = 0;
            int pos = 0;
            while (pos < prev.size()) {
                while (pos < prev.size() && prev[pos] == prev[start]) {
                    pos++;
                }
                cur += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = cur;
        }
        return prev;*/
    }
};