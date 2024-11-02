// 买卖股票的最佳时机 进阶版
// 给一个股票价格的数组 + k，最多可以买卖K次


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;


// 动态规划
// 因为至多交易K次，所以每次交易完成 次数要-1
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    // 考虑初始化边界，对于buy数组，j=0时，每天的利润就买入股票 -股票的额价格
    // 对于sell j=0，利润也是0
    vector<int> buy(k, -prices[0]);
    vector<int> sell(k,0);

    // 从第一天开始
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            buy[j] = max(buy[j],(j==0?0:sell[j-1])-prices[i]);// j-1次的利润，要第j次买，所以减去当前的价格
            sell[j]=max(sell[j], buy[j]+prices[i]);
        }
        
    }

    return sell[k-1];
    
    
    


        
}

int main(){
    int k = 2;
    vector<int> price = {2,4,1};
    int ans = maxProfit(k,price);
    cout << ans <<endl;
}