#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	1640. 能否连接形成数组	
*/
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> index;
        for (int i = 0; i < pieces.size(); i++) {
            //记录pieces中每个数组的起始数字
            index[pieces[i][0]] = i;
        }
        for (int i = 0; i < arr.size(); ) {
            //该数字在index中未出现
            if (index.find(arr[i]) == index.end()) {
                return false;
            }
            //否则的话，就遍历数组
            auto it = index.find(arr[i]);     //找到以arr[i]为起点的下标
            for (auto& p : pieces[it->second]) {
                if (arr[i++] != p) {
                    return false;
                }
            }
        }
        return true;
    }
};