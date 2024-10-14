// 单词搜索

// 单词必须由相邻单元格的字母构成  水平或者垂直  不能重复使用

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool backtrack(vector<vector<char>>& board, string& word, int index, int i, int j){
    
    int m = board.size();
    int n = board[0].size();
    if (index==word.size())
    {
        return true;
    }
    if (i>=m || j >= n || i<0 || j< 0)
    {
        return false;
    }
   
   
    // 查看水平或者垂直  
    if(board[i][j]!=word[index]){
        return false;
    }

        // 找到了 暂时存储  防止回头
        auto tmp = board[i][j];
        board[i][j]='0';
        // 探索接下来的四个方向
        
        bool res = backtrack(board, word, index+1, i, j+1);
        res = res || backtrack(board, word, index+1, i-1, j);
        res= res || backtrack(board, word, index+1, i, j-1);
        res = res || backtrack(board, word, index+1, i+1 ,j);
        // 回溯
        board[i][j]=tmp;

        return res;
    
    
    
    
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "board i j:"<< i << " "<< j <<endl;

            if (board[i][j]==word[0]&&backtrack(board, word, 0, i, j))
            {
                return true;
            }
            
        }
        
    }
    

   
    return false;

}
