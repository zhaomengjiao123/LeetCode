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

// 二刷  矩阵的最小路径和
// 找到矩阵中从左上角到右下角的路径 和 最小  每次只能向下或者向右
// 思路 动态规划
// f i j 表示走到 i，j的最小路径和 fi j= min(fi,j-1,  fi-1,j)+numsi,j
// 初始化：f[0][0]=grid[0][0]
int minPathSum2(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    // 服了 服了 没有初始化  因为是直接填入数据的 所以需要先开辟空间 
    vector<vector<int>> f(n,vector<int>(m));
    f[0][0]=grid[0][0];
    for (int i = 1; i < n; i++)
    {
        f[i][0]=f[i-1][0]+grid[i][0];
    }
    for (int i = 1; i < m; i++)
    {
        f[0][i]=f[0][i-1]+grid[0][i];
    }
    
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            f[i][j]=min(f[i-1][j],f[i][j-1])+grid[i][j];
        }
        
    }
    return f[n-1][m-1];
    



}

int main(){
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    int ans = minPathSum2(grid);
    cout <<ans <<endl;
}
