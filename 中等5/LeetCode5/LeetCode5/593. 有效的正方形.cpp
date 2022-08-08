#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*
	593. 有效的正方形
        判定正方形的三个条件：
            1、两条斜边的中点相同
            2、满足条件1后，两条斜边的长度相同
            3、满足条件2后，两条斜边互相垂直
*/
class Solution {
    //条件1、两条斜边的中点
    bool checkMIdPoint() {
    
    }
    //条件2、两条斜边的长度
    bool checkMidLen() {
    
    }
    //条件3、两条斜边是否互相垂直
    bool checkchuizhi() {
    
    }
    //满足这三个条件就为true
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

    }
};

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> umap;
        vector<vector<int>> nums;
        nums.push_back(p1);
        nums.push_back(p2);
        nums.push_back(p3);
        nums.push_back(p4);

        int n = 4;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (i != j) {
                    int x = pow(nums[i][0] - nums[j][0], 2) + pow(nums[i][1] - nums[j][1], 2);
                    umap[x]++;
                }
            }
        }

        //map内部是按照key从大到小进行排序的，边长长度肯定小于对角线长度
        auto it = umap.begin();
        cout << it->second << endl;
        if (it->second != 4) return false;
        it++;
        cout << it->second << endl;
        if (it->second != 2) return false;

        return true;
    }
};