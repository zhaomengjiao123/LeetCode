/**
 * @file L279.cpp  给定一个数K  找到 和为K 的完全平方数的最小数量
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * 动态规划
 * 关键信息是： n 最大值 是10000， 那么10000以内的完全平方数只有100个  可以先列出来
 * 
 * @param n 
 * @return int 
 */

#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

int numSquares(int n) {
    // 设  fi  是i的最小完全平方数
    vector<int> f(n+1);
    f[0]=0;
    // 从1开始找
    for (int i = 1; i <= n; i++)
    {
        /* code */
        // 将最小的值 初始化为  无穷大
        int minN = INT_MAX;
        // 遍历小于i的所有完全平方数，找到后+这个剩余的完全平方数
        for (int j = 1;j*j <= i ; j++)
        {
            /* code */
            // 维护最小的 minF
            minN = min(minN, f[i-j*j]);

        }
        f[i]=minN+1; // 加1是因为 算上所找到的这个完全平方数  也算是一个
        
    }
    return f[n];
    

}

int main(){
    int n;
    cin >> n;
    int ans = numSquares(n);

    cout << ans << endl;
}