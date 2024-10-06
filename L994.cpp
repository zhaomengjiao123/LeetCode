/**
 * @file L994.cpp 腐烂的橘子
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;

// 每过1min往外扩散一圈 最后检查还有没有新鲜橘子

// void rotting(vector<vector<int>>& grid, int r, int c, int ans){
//     int n = grid.size();
//     int m = grid[0].size();
//     // 向 上下左右扩散
//     // 上
//     if (r-1 >=0 && grid[r-1][c]==1)
//     {
//         grid[r-1][c]==2;
//         rotting(grid, r-1, c, ans);
//     }
//     // 下
//     if (r+1<n && grid[r+1][c]==1)
//     {
//         grid[r+1][c]==2;
//         rotting(grid, r+1, c, ans);
//     }
//     // 左
//     if (c-1>=0 && grid[r][c-1]==1)
//     {
//         grid[r][c-1]==2;
//         rotting(grid, r, c-1, ans);
//     }
//     // 右
//     if (c+1<m && grid[r][c+1]==1)
//     {
//         grid[r][c+1]==2;
//         rotting(grid, r, c+1, ans);
//     }
//     // 本轮扩散耗时
//     ans++;
// }

// int orangesRotting(vector<vector<int>>& grid) {
//     int n = grid.size();
//     int m = grid[0].size();
//     int ans = 0;
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//            //如果遇到腐烂橘子
//            if (grid[i][j]==2)
//            {
//              // 扩散腐烂
//              rotting(grid, i, j, ans);
//            }
           
//         } 
//     }
//     // 判断是否全部腐烂
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//            //如果遇到腐烂橘子
//            if (grid[i][j]==1)
//            {
//              return -1;
//            }
           
//         } 
//     }
//     return ans;
    
    
    

// }
// 深度过深  没法过

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    // 统计新鲜橘子的个数
    int freshNum = 0;
    // bfs统计腐烂句子
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        /* code */
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j]==1)
            {
                freshNum++;
            }
            if (grid[i][j]==2)
            {
                q.emplace(i,j);
            }
            
            
        }
        
    }
    int minutes = 0;
    while (!q.empty())
    {
        if (freshNum==0)
        {
            // 没有烂橘子了
            return minutes;
        }
        // 过去一分钟  开始腐烂
        minutes++;
        int size = q.size();
        // 拿出腐烂句子
        for (int i = 0; i < size; i++)
        {
            pair<int,int> rot = q.front();
            q.pop();
            int x =rot.first;
            int y =rot.second;
            // 朝四个方向腐烂
            freshNum = freshNum - rotting(grid, x-1,y,q);
            freshNum =freshNum -rotting(grid, x,y-1,q);
            freshNum = freshNum - rotting(grid, x+1,y,q);
            freshNum =freshNum -rotting(grid, x,y+1,q);
        }

        

        
    }
    // 腐烂结束，检查还有没有新鲜橘子
    if (freshNum>0)
    {
        return minutes;
    }else{
        return -1;
    }
    
    

    
    
    

}

int rotting(vector<vector<int>>& grid, int x, int y, queue<pair<int,int>>& q){
    // 如果坐标超过边界或者本身没有橘子 就直接返回
    int n = grid.size();
    int m = grid[0].size();
    if (x<0||y<0||x>n-1||y>m-1||grid[x][y]!=1)
    {
        return 0;
    }
    // 否则的话 腐烂
    grid[x][y]=2;
    // 把腐烂的橘子放入队列
    q.emplace(x,y);
    // 腐烂的数量是  1
    return 1;
    
}