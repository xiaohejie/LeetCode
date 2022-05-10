#include<iostream>
using namespace std;
/*
	最小高度树：
		思路：找中心节点（找出叶子结点，然后去除，就会有新的叶子结点介入，再不断删除，直到不存在叶子结点）
		vector<int> res;
		if(n == 1){
			res.push_back(0);
            return res;
		}
		（1）int:创建每个节点的邻居数量
		vector:每个节点的邻居们
		进行初始化：for (auto& edge : edges) {}
		（2）寻找叶子结点
		queue<int> leafNodes;
		(3)循环遍历：
		{
			将叶子结点全部进行删除并更新相关数据；
			然后在将更新后的叶子结点insert进去
			直到不存在叶子结点 
		}
*/