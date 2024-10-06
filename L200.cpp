/**
 * @file L200.cpp 找到二维数组中的岛屿的数量
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// dfs
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

// dfs 每遇到一个1，岛屿的数量+1，并且沿着这个的上下左右四个方向探索，知道把相邻的都变为1
// 并且为了避免重复搜索，要把遇到的1标记为0

void dfs(vector<vector<char>>& grid, int r, int c){
    int nr = grid.size();
    int nc = grid[0].size();
    // 把当前的这个岛屿的位置标记为0
    grid[r][c]='0';
    // 沿四个方向继续探索  注意边界的判断，不要数组溢出
    // 上
    if (r-1>=0&&grid[r-1][c]=='1')
    {
        dfs(grid, r-1,c);
    }
    // 下
    if (r+1<nr&&grid[r+1][c]=='1')
    {
        dfs(grid, r+1,c);
    }
    // 左
    if (c-1>=0&&grid[r][c-1]=='1')
    {
        dfs(grid, r,c-1);
    }
    // 右
    if (c+1<nc&&grid[r][c+1]=='1')
    {
        dfs(grid, r,c+1);
    }
    
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    if (m==0)
    {
        return 0;
    }
    
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        /* code */
        for (int j = 0; j < n; j++)
        {
            /* code */
            if (grid[i][j]=='1')
            {
                /* code */
                ans++;
                dfs(grid, i, j);
            }
            
        }
        
    }
    return ans;
    

        
}