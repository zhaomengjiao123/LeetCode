// 买卖股票的最佳时机  多多可以完成两笔交易
// 在美乳之前必须卖出手里的股票


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


// 思路：动态规划，f[i] 代表 第i天可以获取的最大利润
// f[i] = 

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // 定义四个状态数组
    vector<int> buy1(n);
    vector<int> sell1(n);
    vector<int> buy2(n);
    vector<int> sell2(n);
    // 处理边界条件 初始化
    buy1[0]=-prices[0];
    sell1[0]=0;
    buy2[0]=-prices[0];
    sell2[0]=0;
    for (int i = 1; i < n; i++)
    {
        buy1[i] = max(buy1[i-1], -prices[i]);
        sell1[i] = max(buy1[i-1]+prices[i], sell1[i-1]);
        buy2[i] = max(buy2[i-1], sell1[i-1]-prices[i]);
        sell2[i] = max(sell2[i-1], buy2[i-1]+prices[i]);

    }
    // 因为要进行两次交易，答案是sell2
    return sell2[n-1];
    

        
}


int main(){
    vector<int> price = {3,3,5,0,0,3,1,4};
    int ans = maxProfit(price);
    cout << ans << endl;
}