#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
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

/*
    1582. �����ƾ����е�����λ��
*/
class Solution {
public:
    int helper(int row , int col , int rows, int cols, vector<vector<int>>& mat) {
        //������i�к͵�j��
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
    1592. �������е��ʼ�Ŀո�
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
    1598. �ļ��в�����־�Ѽ���
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
    1608. �������������ֵ
*/
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            //��i��Ԫ�ش��ڵ���i���ң������i+1��Ԫ�ش��ڵĻ�����Ԫ��С��i��
            if ((nums[i - 1] >= i) && (n == i || nums[i] < i)) {
                return i;
            }
        }
        return -1;
    }
};

/*
    1619. ɾ��ĳЩԪ�غ�������ֵ
*/
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int num = n * 0.05;
        int sum = 0;
        for (int i = num; i < n - num; i++) {
            sum += arr[i];
        }
        return (double)sum / (n - num * 2);
    }
};

/*
    1624. ������ͬ�ַ�֮�������ַ���
*/
class Solution {
public:
    unordered_map<char, vector<int>> map;
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            //cout << s[i] << " " << i << endl;
            map[s[i]].push_back(i);
        }
        for (auto m : map) {
            int len = m.second.size();
            if (len == 1) {
                ans = max(ans, -1);
            }
            vector<int> vec = m.second;
            ans = max(ans, vec[len - 1] - vec[0]);
        }
        return ans;
    }
};

/*
    1636. ����Ƶ�ʽ�������������
*/
class Solution {
    unordered_map<int, int> map;
public:
    vector<int> frequencySort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b) {
            if (map[a] < map[b]) {
                return true;
            }
            else if (map[a] == map[b]) {
                return a > b;
            }
            return false;
            });
        return nums;
    }
};

/*
    1640. �ܷ������γ�����
*/
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {

    }
};

/*
    1652. ��ը��
*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> newCode(code.size(), 0);
        if ( k == 0) {
            return newCode;
        }
        for (int i = 0; i < code.size(); i++) {
            int sum = 0;
            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % code.size()];
                }
            }
            else {
                for (int j = i + k; j < i; j++) {
                    sum += code[(j + code.size()) % code.size()];
                }
                
            }
            newCode[i] = sum;
        }
        return newCode;
    }
};