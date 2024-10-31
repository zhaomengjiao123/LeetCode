// 生命游戏 m*n 面板，每个格子 1 活的，0死的
// 死亡和存活是同时发生的（所以我们不能直接修改原位置）


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;


// 另开一个矩阵存储结果，遍历一遍
// 偏移值
void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();
    // 单开结果数组
    vector<vector<int>> ans(n,vector<int>(m));
    // 偏移数组
    vector<int> offset = {0,1,-1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 如果当前是死细胞
             int live_num = 0;
                // 查看有没有复活的可能
                for (int r = 0; r < 3; r++)
                {
                    for (int c = 0; c < 3; c++)
                    {
                        // 删除原位置
                        if (!(offset[r]==0 && offset[c]==0))
                        {
                            int cur_r = i+offset[r];
                            int cur_c = j+offset[c];
                            if ((cur_r<n&&cur_r>=0)&&(cur_c<m&&cur_c>=0) )
                            {
                                if (board[cur_r][cur_c]==1)
                                {
                                    live_num++;
                                }
                                
                            }
                            
                        }
                        
                        
                    }
                    
                }
                // 如果当前是死细胞，看看能不能复活
                ans[i][j]=board[i][j];
            if (board[i][j]==0&&live_num==3)
            {
               
                // 复活
                ans[i][j]=1; 
            }
            if (board[i][j]==1 && (live_num<2||live_num>3)) // 如果是活细胞
            {
                ans[i][j]=0;
            }
            if(board[i][j]==1 && live_num>3){
                ans[i][j]=0;
            }
            
            
                
                
                
            
            
        }
        
    }

    board = ans;
    
        
}