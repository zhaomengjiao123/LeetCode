//零钱兑换 每种硬币的数量不限
// 思路：动态规划  遍历硬币  如果存在当前金额-当前硬币金额 的最小数量

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


 int coinChange(vector<int>& coins, int amount){
    // dp[i]为凑齐总金额为i所需要的最少硬币
    // 遍历目前拥有的硬币
    // dp[i]=min(dp[i],dp[i-coins[]+1])
    // 先判断特殊情况
    sort(coins.begin(), coins.end());
    int min_coins = coins[0];
    if(amount<min_coins){
        // 比最小的conis还小 不可能凑齐
        return -1;
    }
    // 从0-amount  开始凑
    vector<int> dp(amount+1, amount*2);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        // 遍历当前的硬币
        for(int j=0;j<coins.size();j++){
            // 但是只遍历硬币小于当前金额的
            if(coins[j]<=i){
                dp[i]=min(dp[i], dp[i-coins[j]]+1);
            }
            
        }
    }
    // 判断最后的结果
    return dp[amount]==amount*2?-1:dp[amount];

 }

 int main(){
    vector<int> coins={1,2,5};
    int amount = 11;
    int ans = coinChange(coins, amount);
    cout<<ans<<endl;
 }