// N皇后问题

// 皇后攻击 同一行 或者同一列棋子  或 同一斜列
// n 哥皇后放置在n n棋盘上并且不能相互攻击

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

// 回溯？

vector<vector<string>> ans;
vector<string> tmp;

// 生成输出形式
vector<string> generateBoard(vector<int>& queens, int n){
    auto board = vector<string>();
    for (int i = 0; i < n; i++)
    {
        string row = string(n, '.');
        row[queens[i]]='Q';
        board.push_back(row);
    }
    return board;
}

void dfs(vector<vector<string>>& solutions, vector<int>& queen, 
int n, int row, unordered_set<int>& columns, unordered_set<int>& dignals1, 
unordered_set<int>& diagonals2){
    // 如果皇后 放完了
    // 因为每一行肯定只能放一个皇后  每一列也是
    if (row==n)
    {
        // 生成一种方案；
        vector<string> board = generateBoard(queen, n);
        solutions.push_back(board);
        

    }else{
        // 正常遍历  排除已经有皇后的行和列 
        for (int i = 0; i < n; i++)
        {
            if (columns.find(i)!=columns.end())
            {
                // 已有  不可以再放
                continue;
            }
            // 并且也不能在  同一个斜列里面
            int subN = row-i;
            if (dignals1.find(subN)!=dignals1.end())
            {
                continue;
            }
            int sbN2 = row + i;
            if (diagonals2.find(sbN2)!=diagonals2.end())
            {
                continue;
            }
            // 可以放
            queen[row]=i;
            // 插入当前皇后的位置
            columns.insert(i);
            // 对角线插入
            dignals1.insert(subN);
            diagonals2.insert(sbN2);
            // 继续寻找下一个位置
            dfs(solutions,queen,n,row+1,columns,dignals1,diagonals2);
            // 回溯
            queen[row]=-1;
            columns.erase(i);
            dignals1.erase(subN);
            diagonals2.erase(sbN2);
            
            
            
        }
        

    }
    
    
    

}


vector<vector<string>> solveNQueens(int n) {

    auto solutions = vector<vector<string>>();
    auto queens = vector<int>(n,-1);
    auto colums = unordered_set<int>();
    auto diagonals1 = unordered_set<int>(); // 对角线1  在这条线上 i j的差是相等的
    auto diagonals2 = unordered_set<int>(); // 对角线2 在这条线上 i j的和是相等的
    // 开始回溯遍历
    dfs(solutions,queens,n,0,colums, diagonals1, diagonals2);
    return solutions;


}