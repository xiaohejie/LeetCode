#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
	929、独特的电子邮件地址:
        遍历每个电子邮件的真实发送地址
        用set记录
*/
class Solution {
public:
    unordered_set<string> set;
    void helper(string& email) {
        //将本地名和域名分开
        int idx = email.find("@");
        string email1 = email.substr(0, idx);       //本地名
        string email2 = email.substr(idx + 1, email.size() - idx);      //域名
        string newEmail1 = "";
        //遍历本地名
        for (int i = 0; i < email1.size(); i++) {
            //如果发现“.”，就直接跳过去
            if (email1[i] == '.') {
                i++;
            }
            //发现“+”,break
            if (email1[i] == '+') {
                break;
            }
            newEmail1 += email1[i];
        }
        //记录真实地址
        string newEmail = newEmail1 + "@" + email2;
        set.insert(newEmail);
    }
    int numUniqueEmails(vector<string>& emails) {
        for (auto& email : emails) {
            //找出真实地址，并记录
            helper(email);
        }
        int count = set.size();
        return count;
    }
};