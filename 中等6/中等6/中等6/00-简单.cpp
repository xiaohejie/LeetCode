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

/*
    1582. 二进制矩阵中的特殊位置
*/
class Solution {
public:
    int helper(int row , int col , int rows, int cols, vector<vector<int>>& mat) {
        //遍历第i行和第j列
        for (int i = 0; i < cols; i++) {
            if (mat[row][i] == 1) {
                return 0;
            }
        }
        for (int i = 0; i < rows; i++) {
            if (mat[i][col] == 1) {
                return 0;
            }
        }
        return 1;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    ans += helper(i, j, rows, cols, mat);
                }
            }
        }
        return ans;
    }
};

/*
    1592. 重新排列单词间的空格
*/
class Solution {
    vector<string> str;
    int count = 0;
public:
    string reorderSpaces(string text) {
        int index = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text[i]) {
                
            }
        }
    }
};

/*
    1598. 文件夹操作日志搜集器
*/
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto& log : logs) {
            if (log == "./") {
                continue;
            }
            else if (log == "../") {
                if (depth > 0) {
                    depth--;
                }
            }
            else {
                depth++;
            }
        }
        return depth;
    }
};

/*
    1608. 特殊数组的特征值
*/
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            //第i个元素大于等于i并且（如果第i+1个元素存在的话，该元素小于i）
            if ((nums[i - 1] >= i) && (n == i || nums[i] < i)) {
                return i;
            }
        }
        return -1;
    }
};