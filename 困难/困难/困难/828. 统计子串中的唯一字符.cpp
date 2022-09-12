#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
    828. ͳ���Ӵ��е�Ψһ�ַ�
        ��ѧԭ����
*/
class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> index;
        //��¼ÿ���ַ��ڸ��ַ����г��ֵ�λ��
        for (int i = 0; i < s.length(); i++) {
            index[s[i]].push_back(i);
        }
        int res = 0;
        for (auto&&[_, arr] : index) {
            //��ͷ��β���в��룬����Ϊʲô����������צ����˹��
            arr.insert(arr.begin(), -1);
            arr.push_back(s.size());

            for (int i = 1; i < arr.size() - 1; i++) {
                res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return res;
    }
};