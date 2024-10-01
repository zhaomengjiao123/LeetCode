/**
 * @file L70.cpp 爬楼梯
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// fn 表示爬到n阶的方法 fn = fn-1+fn-2
// f1=1 f2=2
// 动态规划
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int climbStairs(int n){
    vector<int> f(n+1,0);

    if (n<3)
    {
        // 直接返回
        return n;
    }
    f[1]=1;
    f[2]=2;
    
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
    
}

int main(){
    int n;
    cin>>n;

    int ans = climbStairs(n);
    cout<<n<<endl;
}