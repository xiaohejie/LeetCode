#include<iostream>
#include<string>
using namespace std;
/*
    ������У���ʹ�ö�̬�滮��
        ��n==1ʱ{
            return ��1����
        }
        string tmp = helper(n-1);       //���ص���ǰһ��shu�Ľ��
        string ans = "";
        char ch = tmp[0];
        //�������n�Ľ��
        int n = ans.length();
        int count = 1;      //��¼����
        for(int i = 1; i < n; i++){
            if(tmp[i] == tmp[i-1]){
                //i��i-1��ͬ
                count++;
                continue;
            }
            else{
                //i != i-1����Ҫ����ans
                ans += to_string(count);
                ans += to_string(ch);
                //��������
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
            //��ͬ
            if (tmp[i] == tmp[i - 1]) {
                count++;
                continue;
            }
            //��ͬ������ans
            ans += to_string(count);
            ans += ch;
            //����count��ch
            count = 1;
            ch = tmp[i];
        }
        return ans;
    }
    string countAndSay(int n) {
        //��2���ݹ�
        return helper(n);



        //��һ��
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