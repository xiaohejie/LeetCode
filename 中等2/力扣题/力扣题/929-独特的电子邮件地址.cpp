#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
	929�����صĵ����ʼ���ַ:
        ����ÿ�������ʼ�����ʵ���͵�ַ
        ��set��¼
*/
class Solution {
public:
    unordered_set<string> set;
    void helper(string& email) {
        //���������������ֿ�
        int idx = email.find("@");
        string email1 = email.substr(0, idx);       //������
        string email2 = email.substr(idx + 1, email.size() - idx);      //����
        string newEmail1 = "";
        //����������
        for (int i = 0; i < email1.size(); i++) {
            //������֡�.������ֱ������ȥ
            if (email1[i] == '.') {
                i++;
            }
            //���֡�+��,break
            if (email1[i] == '+') {
                break;
            }
            newEmail1 += email1[i];
        }
        //��¼��ʵ��ַ
        string newEmail = newEmail1 + "@" + email2;
        set.insert(newEmail);
    }
    int numUniqueEmails(vector<string>& emails) {
        for (auto& email : emails) {
            //�ҳ���ʵ��ַ������¼
            helper(email);
        }
        int count = set.size();
        return count;
    }
};