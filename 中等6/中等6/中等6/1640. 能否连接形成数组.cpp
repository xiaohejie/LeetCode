#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	1640. �ܷ������γ�����	
*/
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> index;
        for (int i = 0; i < pieces.size(); i++) {
            //��¼pieces��ÿ���������ʼ����
            index[pieces[i][0]] = i;
        }
        for (int i = 0; i < arr.size(); ) {
            //��������index��δ����
            if (index.find(arr[i]) == index.end()) {
                return false;
            }
            //����Ļ����ͱ�������
            auto it = index.find(arr[i]);     //�ҵ���arr[i]Ϊ�����±�
            for (auto& p : pieces[it->second]) {
                if (arr[i++] != p) {
                    return false;
                }
            }
        }
        return true;
    }
};