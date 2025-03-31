#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> costs(n),prices(n);

    for(int i=0;i<n;i++){
        cin>>costs[i]>>prices[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // 前 i道菜在预算为j时的收益
    for(int i=1;i<=n;i++){
        int a = costs[i-1];
        int b = prices[i-1];

        for(int j=1;j<=m;j++){
            // 不选当前菜品
            dp[i][j]=dp[i-1][j];
            // 选当前菜品   
            if(j>=b){
                dp[i][j]=max(dp[i][j],dp[i-1][j-b]+(b-a));
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}