#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
	1175. 质数排列
        将所有质数的排列和所有合数的排列进行相乘
*/
class Solution {
    int mod = 1e9 + 7;
public:
    //判断是否是质数
    bool isZhishu(int n) {
        if (n == 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        for (int i = 2; i < n / 2; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        int isCount = 0, noCount = 0;
        //得到质数和合数的个数
        for (int i = 1; i <= n; i++) {
            if (isZhishu(i)) {
                isCount++;
            }
            else {
                noCount++;
            }
        }
        //计算排列组合
        int isSum = 1, noSum = 1;
        for (int i = isCount; i > 1; i--) {
            isSum *= i;
            isSum %= mod;
        }
        for (int i = noSum; i > 1; i--) {
            noSum *= i;
            noSum %= mod;
        }
        return (isSum * noSum) % mod;
    }
};

/*
    496. 下一个更大元素 I
*/
class Solution496 {
public:
    //找出某个元素在一个数组中对应位置右侧第一个的数
    int helper(int num, vector<int>& nums) {
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (num == nums[i]) {
                index = i;
                break;
            }
        }
        for (int i = index; i < nums.size(); i++) {
            if (nums[i] > num) {
                return nums[i];
            }
        }
        return - 1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int res = helper(nums1[i], nums2);
            ans.push_back(res);
        }
        return ans;
    }
};

/*
    1200. 最小绝对差
        排序+一次遍历
*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        //经过排序后，最小绝对差的元素对一定是相邻的两个元素
        int minValue = INT_MAX;
        vector<int> vec;
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++) {
            if (minValue > abs(arr[i]-arr[i-1])) {
                //修改最小差
                minValue = abs(arr[i] - arr[i - 1]);
                //清零
                ans.clear();
                ans.push_back({arr[i-1], arr[i]});
            }
            else if (minValue == abs(arr[i] - arr[i - 1])) {
                ans.push_back({ arr[i - 1], arr[i] });
            }
        }
        return ans;
    }
};


/*
    面试题 01.03. URL化
        从后往前（使用了额外空间）
        不使用额外空间（因为题目中说了字符串尾部有足够的空间存放新增字符）
*/
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int lenFact = 0;
        string ans;
        lenFact = S.size();
        if (lenFact == length) {
            //将所有的空格全部填充
            for (int i = 0; i < length; i++) {
                if (S[i] == ' ') {
                    ans += '%';
                    ans += '2';
                    ans += '0';
                }
                else {
                    ans += S[i];
                }
            }
        }
        else {
            //倒置，从后往前
            reverse(S.begin(), S.end());
            for (int i = 0; i < length; i++) {
                if (lenFact != length && S[i] == ' ') {
                    lenFact--;
                    continue;
                }
                else if (S[i] == ' ') {
                    ans += '0';
                    ans += '2';
                    ans += '%';
                }
                else {
                    ans += S[i];
                }
            }
        }   
        return ans;
    }
    //不使用额外空间的解法
    string replaceSpaces1(string S, int length) {
        int fillIdx = S.size() - 1;
        int i = 0;
        for (i = length - 1; i >= 0; i--) {
            if (S[i] == ' ') {
                S[fillIdx] = '0';
                S[fillIdx - 1] = '2';
                S[fillIdx - 2] = '%';
                fillIdx -= 3;
            }
            else {
                S[fillIdx] = S[i];
                fillIdx--;
            }
        }
        S = S.substr(fillIdx + 1);
        return S;
    }
};


/*
    190. 颠倒二进制位
*/
class Solution190 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32 && n > 0; i++) {
            //先将n与1按位与，然后换位置（倒置，如第0位移到31位）
            ans |= (n & 1) << (31 - i);
            //n不断右移
            n >>= 1;
        }
        return ans;
    }
};

/*
    228. 汇总区间
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int len = nums.size();
        int i = 0;
        while (i < len) {
            int low = i;
            i++;
            while (i < len && nums[i-1] + 1 == nums[i]) {
                i++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};