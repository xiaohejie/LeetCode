#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
/*
	1464. ��������Ԫ�ص����˻�
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxRes = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

            }
        }
    }
};

/*
    1470. ������������
*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }
};

/*
    1047. ɾ���ַ����е����������ظ���
            ����ջ��˼�루����ֱ��ʹ��ջҲ��������string��Ҳ�����õ�ջ����
*/
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string ans = "";
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                //���ջ��Ϊ��
                st.emplace(s[i]);
                //������һ��ѭ��
                continue;
            }
            if (s[i] = st.top()) {
                //��������Ԫ����ͬ
                st.pop();
            }
            else {
                //��������Ԫ�ز�ͬ���ͷ���ջ��
                st.emplace(s[i]);
            }
        }
        //��Ԫ�ط���ans��
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        //��Ҫ���з�ת
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
    1475. ��Ʒ�ۿۺ�����ռ۸�
*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            int price = prices[i];
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= price) {
                    price -= prices[j];
                    break;
                }
            }
            ans.push_back(price);
        }
        return ans;
    }
};