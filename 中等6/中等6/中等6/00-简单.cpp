#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
/*
	1464. 数组中两元素的最大乘积
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
    1470. 重新排列数组
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
    1047. 删除字符串中的所有相邻重复项
            利用栈的思想（可以直接使用栈也可以利用string（也是利用的栈））
*/
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string ans = "";
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                //如果栈中为空
                st.emplace(s[i]);
                //进行下一次循环
                continue;
            }
            if (s[i] = st.top()) {
                //连续两个元素相同
                st.pop();
            }
            else {
                //连续两个元素不同，就放入栈中
                st.emplace(s[i]);
            }
        }
        //将元素放入ans中
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        //需要进行反转
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
    1475. 商品折扣后的最终价格
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