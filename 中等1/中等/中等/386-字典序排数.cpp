#include<iostream>
#include <vector>
/*
    �ֵ��������� 
        num = 1;
        for(i = 0; i < n; i++){
            //��1��ʼ
            res[i] = num;
            if(num * 10 <= n){
            //���num*10С��n�Ļ����Ϳ���
                num *= 10;
            }else{
                while(num >= n || num % 10 == 9){
                    num /= 10;
                }
                num++;
            }
        }
*/
using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int num = 1;
        for (int i = 0; i < n; i++) {
            cout << num << endl;
            res[i] = num;
            if (num * 10 <= n) {
                num *= 10;
            }
            else {
                while (num % 10 == 9 || num >= n)
                {
                    num /= 10;
                }
                num++;
            }
        }
        return res;
    }
};