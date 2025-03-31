/**
 * @file 2025ZiJie-1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/**
 * hy新开了一个小卖部，为了能够更好的卖商品，听了zzh的建议:在店门口摆上展示柜来吸引顾客。于是hy买了一个有m个格子的展示柜，格子从左到右，排成一整排。
在店内，一共有n种不同种类的商品可以用于展示，种类编号依次为1,2,.. ., n。hy决定从中选出m(m ≤n)种商品，将展示柜的每一个格子都放上一种商品，特别地，在放入的过程中，hy决定不打乱这些商品原有的相对顺序，即放在展示柜左边的商品编号一定小于放在展示柜右边的商品编号。
但是商品们摆放在一起会产生不同的化学效应，导致看起来更加美观或者不那么美观，为了方便进行计算，hy统计了这n种商品单独放入展示柜时的吸引力a，而最终放入展示柜的m种商品能够产生的总吸引力是相邻两种商品的吸引力之差绝对值的和。例如有5种商品，吸引力分别为1,2,5,4,3，选出第一、三、五件商品，那么总吸引力即为
la1 - a3/ + |a3 - a5|=|1-5+|5-3 =6。
现在hy想知道，选出的m种商品的吸引力最大可以达到多少?
作r
第一行输入两个整数n, m (1 ≤m≤ n ≤300)代表商品的种类数、展示柜的格子数。
第二行输入n个整数
a1, a2,. . . , an (-1e9≤ai ≤1e10)代表每种商品单独放入展示柜时的吸引力。


 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // 特殊情况判断
    if(m==1||m==0){
        cout<<0<<endl;
        return 0;
    }
    vector<long long> prev(n,0);
    vector<vector<long long>> dp(n,vector<long long>(m+1,LLONG_MIN));
    for(int i=0;i<n;i++){
        dp[i][1] = 0; // 初始化第一列为0  就是选一个商品 吸引力为0
    }
    for(int j=2;j<=m;j++){
        for(int i=j-1;i<n;i++){
            for(int k=0;k<i;k++){
                if(dp[k][j-1]!=LLONG_MIN){
                    dp[i][j] = max(dp[i][j],dp[k][j-1]+abs(a[i]-a[k]));
                }
            }
        }
    }
    // for(int k=2;k<=m;k++){
    //     vector<long long> cur(n, 0);
    //     long long cur_max_minus = 0;
    //     long long cur_max_plus = 0;
    //     for(int i=0;i<n;i++){
    //         if(i>=k-1){
    //             cur[i] = max(cur_max_minus+a[i],cur_max_plus-a[i]);
    //         }
    //         if(i>=1){
    //             cur_max_minus = max(cur_max_minus,prev[i-1]-a[i]);
    //             cur_max_plus = max(cur_max_plus,prev[i-1]+a[i]);
    //         }
            
    //     }
    //     prev = cur;
    // }

    // int ans = *max_element(dp.begin(), dp.end());
    long long ans = LLONG_MIN;
    for(int i=0;i<n;i++){
        if(dp[i][m]>ans){
            ans = dp[i][m];
        }
    }
    cout<<ans<<endl;



    
}