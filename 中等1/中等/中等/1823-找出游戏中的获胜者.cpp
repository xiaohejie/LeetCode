#include<iostream>
#include<queue>
using namespace std;
/*
	找出游戏中的获胜者：
		使用队列+模拟
		（1）将1-n个数放入到队列中
		（2）然后进行循环{
			将对头重新加入队尾，将原来的对头进行删除，最终让第k个数在对头
			将对头进行删除（这样就删除了第k个数）
		}
		（3）返回对头
*/
class Solution {
public:
	int findTheWinner(int n, int k) {
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			//将1-n加入到队列中
			q.emplace(i);
		}
		//进行游戏模拟
		while (q.size() > 1) {
			//不断进行k次循环，将第k个数放到头部
			for (int i = 1; i <= k; i++) {
				q.emplace(q.front());
				q.pop();
			}
			//再进行删除
			q.pop();
		}
		return q.front();
	}
};