// 爬楼梯  动态规划
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// dp[i] 代表爬到第i阶台阶的所有方法
int climbStairs(int n){
    vector<int> dp(n+1);
    // 问题：索引是从0开始的
    dp[0]=1;
    dp[1]=1;
    if(n==1){
        return dp[n];
    }
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];  
}

int main(){
    int n;
    cin>>n;


    int ans = climbStairs(n);
    cout<<ans<<endl;
}