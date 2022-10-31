#include<iostream>
#include<vector>
using namespace std;
/*
	779. 第K个语法符号
        递归（找出第n行第k个字符与第1行的这个0的演变关系）
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (k == 1) {
            return 0;   //向上遍历到了第1行，则返回结果
        }
        if (k > ( 1 << n-2)) {      //1 << n-2：将1左移n-2位   0000 0001 --->  0000 1000
            return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2)));   // 如果在“蓝色区间”，则与上一行值相反（与1进行异或，就是去反 1^0 = 1 1^1 = 0）
        }
        else {
            return kthGrammar(n-1, k);   // 如果在“黄色区间”，则与上一行值相同
        }
    }
};

//该方法不行，会溢出（没办法赋数字类型）
class Solution {
public:
    int kthGrammar(int n, int k) {
        vector<vector<int>> ans(n+1);
        ans[1].push_back(0);
        for (int i = 2; i <= n; i++) {
            //从第二行开始，遍历起那一行的数
            for (int j = 0; j < ans[i - 1].size(); j++) {
                if (ans[i - 1][j] == 0) {
                    ans[i].push_back(0);
                    ans[i].push_back(1);
                }
                else {
                    ans[i].push_back(1);
                    ans[i].push_back(0);
                }
            }
        }
        //返回最后一行的第k-1个数
        return ans[n][k - 1];
    }
};