#include<iostream>
#include<vector>
using namespace std;
/*
	799. ������
        ֱ��ģ��
        ����ÿһ���������ֻ����һ����������йأ�������ǿ����ù�������ķ�ʽ�Ż��ռ临�Ӷȣ�����ά�����Ż�Ϊһά���顣
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = { (double)poured };        //��ʼ����0��������� 
        for (int i = 1; i <= query_row; i++) {          //����ѭ���� ֱ��������Ҫ����һ��
            vector<double> nextRow(i + 1, 0.0);         //��ʼ����һ���������
            for (int j = 0; j < row.size(); j++) {      //������ǰ�����е�����
                double volume = row[j]; 
                if (volume > 1) {                       //����ò�ĵ�j��������������1������Ҫ��������һ��
                    //������һ���������
                    nextRow[j] += (volume - 1) / 2;
                    nextRow[j + 1] += (volume - 1) / 2;
                }
            }
            row = nextRow;          //���µ�ǰ��
        }
        return min(1.0, row[query_glass]);      //������Ҫ��1�����жϣ���Ϊ���п���������һ��
    }
};