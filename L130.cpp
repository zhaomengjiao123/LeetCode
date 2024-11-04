// 被围绕的区域  捕获所有被围绕的区域
// 思路：直接遍历检查？只要不是在边缘都可以直接替换  周围是 X

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
using namespace std;

void dfs(vector<vector<char>>& board, int r, int c){
    // 当前位置是O  ，判断周围有没有相邻的O
    int n = board.size();
    int m = board[0].size();
    // 先将当前的位置标记为F
    board[r][c]='F';
    // 探索上面
    if(r-1>=0 && board[r-1][c]=='O')
    {
        dfs(board,r-1,c);
    }
    // 下面
    if(r+1<n&&board[r+1][c]=='O'){
        dfs(board,r+1,c);
    }
    // 左面
    if (c-1>=0&&board[r][c-1]=='O')
    {
        dfs(board,r,c-1);
    }
    // 右面
    if (c+1<m&&board[r][c+1]=='O')
    {
        dfs(board, r,c+1);
    }
    
    
    

    
    
    
}

// 思路是从边缘的O开始标记，如果与边缘的O事相接触的标记为不可围绕，比如F，后头遍历的时候，在把F还原为O
// 那么后面再遍历遇到O的话就是可以围绕的，替换为X DFS

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    // 查找边缘
    // 第一行
    for (int i = 0; i < m; i++)
    {
        if (board[0][i]=='O')
        {
            // 探索
            dfs(board, 0, i);
        } 
    }

        // 第一列
    for (int i = 0; i < n; i++)
    {
        if (board[i][0]=='O')
        {
            // 探索
            dfs(board, i, 0);
        } 
    }
    // 最后一行
    for (int i = 0; i < m; i++)
    {
        if (board[n-1][i]=='O')
        {
            // 探索
            dfs(board, n-1, i);
        } 
    }
    // 最后一列
    for (int i = 0; i < n; i++)
    {
        if (board[i][m-1]=='O')
        {
            // 探索
            dfs(board, i, m-1);
        } 
    }

    // 遍历矩阵 遇到X跳过，遇到 O 变为X，遇到F还原为O
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j]=='F')
            {
                board[i][j]='O';
            }else if (board[i][j]=='O')
            {
                board[i][j]='X';
            }
            
            
        }
        
    }
    
    
        
}


int main(){
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    solve(board);
    for (auto row:board)
    {
        for (auto c:row)
        {
            cout << c <<" ";
        }
        cout << endl;
        
    }

    
}