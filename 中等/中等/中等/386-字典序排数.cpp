#include<iostream>
#include <vector>
/*
    字典序排数： 
        num = 1;
        for(i = 0; i < n; i++){
            //从1开始
            res[i] = num;
            if(num * 10 <= n){
            //如果num*10小于n的话，就可以
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