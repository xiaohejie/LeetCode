#include<iostream>
#include<vector>
#include <queue>
using namespace std;
/*
	1801. 积压订单中的订单总数
*/
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int MOD = 1000000007;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> buyOrders;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sellOrders;
        for (auto&& order : orders) {
            //记录该订单的信息 
            int price = order[0], amount = order[1], orderType = order[2];
            if (orderType == 0) {   //如果是采购订单
                while (amount > 0 && !sellOrders.empty() && sellOrders.top().first <= price)
                {
                    auto sellOrder = sellOrders.top();
                    sellOrders.pop();       //弹出top
                    int sellAmount = min(amount, sellOrder.second); //记录数量小的订单
                    amount -= sellAmount;
                    sellOrder.second -= sellAmount;
                    if (sellOrder.second > 0) {
                        sellOrders.push(sellOrder);
                    }
                }
                if (amount > 0) {
                    buyOrders.emplace(price, amount);
                }
            }
            else {
                while (amount > 0 && !buyOrders.empty() && buyOrders.top().first >= price) {
                    auto buyOrder = buyOrders.top();
                    buyOrders.pop();
                    int buyAmount = min(amount, buyOrder.second);
                    amount -= buyAmount;
                    buyOrder.second -= buyAmount;
                    if (buyOrder.second > 0) {
                        buyOrders.push(buyOrder);
                    }
                }
                if (amount > 0) {
                    sellOrders.emplace(price, amount);
                }
            }
        }
        int total = 0;
        while (!buyOrders.empty()) {
            total = (total + buyOrders.top().second) % MOD;
            buyOrders.pop();
        }
        while (!sellOrders.empty()) {
            total = (total + sellOrders.top().second) % MOD;
            sellOrders.pop();
        }
        return total;
    }
};