// 买卖股票的最佳时机
// 每个时刻只能持有一个股票，每一天都可以买入或者卖出
// 不限制买入和卖出的次数

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


// 第一种思路是 动态规划  f[i][0]表示在第i天手里没有股票时的最大利润 f[i][1] 表示手里有一个股票的最大利润
// 那么 f[i][0] = max(f[i-1][0],f[i-1][1]+priexs[i])[如果前一天手里有骨片，但是今天手里诶有了，说明卖出去了，利润+当天的骨片的利润]
// f[i][1] = max(f[i-1][0]-prie[i], f[i-1][1]);
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n==1)
    {
        return 0;
    }
    vector<vector<int>> f(n, vector<int>(n));
    // 初始化边界条件
    f[0][1] = -prices[0];
    f[0][0] = 0;
    for (int i = 1; i < n; i++)
    {
        f[i][0] = max(f[i-1][0], f[i-1][1]+prices[i]);
        f[i][1] = max(f[i-1][0]-prices[i], f[i-1][1]);
    }

    return max(f[n-1][0],f[n-1][1]);
    
    
        
}

// 第二种思路，因为不限制买卖的次数，我们把所有能挣钱的情况都卖出
int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    if (n==0||n==1)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i]>prices[i-1])
        {
            ans = ans + (prices[i]-prices[i-1]);
        }
        
    }
    return ans;
    
    

}

int main(){
    vector<int> nums = {
        7,1,5,3,6,4
    };

    int ans = maxProfit(nums);

    cout << ans << endl;
}