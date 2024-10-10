/**
 * @file L64.cpp
 * @author zmj 
 * @brief 
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
*/
// 每次只能向右或者向下  找到路径和最小
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 动态规划 f[i][j] 代表i,j处和最小
// fi,j = min (fi-1,j, fi,j-1) nums i
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> f(m, vector<int>(n));
    f[0][0]=grid[0][0];
    // 初始化第一列和第一行
    for (int i = 1; i < m; i++)
    {
        f[i][0]=f[i-1][0]+grid[i][0];
    }
    for (int i = 1; i < n; i++)
    {
        f[0][i]=f[0][i-1]+grid[0][i];
    }
    
    

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            f[i][j]=min(f[i-1][j],f[i][j-1])+grid[i][j];
        }
        
    }
    return f[m-1][n-1];
}
