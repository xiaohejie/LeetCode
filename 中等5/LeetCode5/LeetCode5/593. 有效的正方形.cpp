#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*
	593. ��Ч��������
        �ж������ε�����������
            1������б�ߵ��е���ͬ
            2����������1������б�ߵĳ�����ͬ
            3����������2������б�߻��ഹֱ
*/
class Solution {
    //����1������б�ߵ��е�
    bool checkMIdPoint() {
    
    }
    //����2������б�ߵĳ���
    bool checkMidLen() {
    
    }
    //����3������б���Ƿ��ഹֱ
    bool checkchuizhi() {
    
    }
    //����������������Ϊtrue
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

        //map�ڲ��ǰ���key�Ӵ�С��������ģ��߳����ȿ϶�С�ڶԽ��߳���
        auto it = umap.begin();
        cout << it->second << endl;
        if (it->second != 4) return false;
        it++;
        cout << it->second << endl;
        if (it->second != 2) return false;

        return true;
    }
};