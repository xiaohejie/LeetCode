#include<iostream>
#include<vector>
using namespace std;
/*
	799. 香槟塔
        直接模拟
        由于每一层的香槟量只与上一层的香槟量有关，因此我们可以用滚动数组的方式优化空间复杂度，将二维数组优化为一维数组。
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = { (double)poured };        //初始化第0层的香槟量 
        for (int i = 1; i <= query_row; i++) {          //进行循环， 直到我们需要的那一层
            vector<double> nextRow(i + 1, 0.0);         //初始化下一层的香槟量
            for (int j = 0; j < row.size(); j++) {      //遍历当前层所有的香槟
                double volume = row[j]; 
                if (volume > 1) {                       //如果该层的第j被香槟容量超过1，就需要流出到下一层
                    //更新下一层的香槟量
                    nextRow[j] += (volume - 1) / 2;
                    nextRow[j + 1] += (volume - 1) / 2;
                }
            }
            row = nextRow;          //更新当前层
        }
        return min(1.0, row[query_glass]);      //返回需要与1进行判断，因为还有可能流入下一层
    }
};