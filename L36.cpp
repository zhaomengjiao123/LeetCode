// 有效的数独
// 判断 9*9的数独是否有效？

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

// 思路 存储每一行 每一列  每一个小九宫格中数字出现的次数，不可以重复
bool isValidSudoku(vector<vector<char>>& board) {
    // 这个数独的大小是不变的 9*9 所以直接开这么大的数组！
    vector<vector<int>> rows(9, vector<int>(9));
    vector<vector<int>> cols(9, vector<int>(9));
    vector<vector<vector<int>>> littleb(3,vector<vector<int>>(3,vector<int>(9)));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (isdigit(board[i][j]))
            {
                // 查看对应的行是不是已经有数了
                if (rows[i][board[i][j]-'0'-1]==1||cols[board[i][j]-'0'-1][j]==1
                || littleb[i/3][j/3][board[i][j]-'0'-1]==1)
                {
                    return false;
                }else{
                    // 存入，对应的位置变为1
                    rows[i][board[i][j]-'0'-1]=1;
                    cols[board[i][j]-'0'-1][j]=1;
                    littleb[i/3][j/3][board[i][j]-'0'-1]=1;
                }
                
                
                
            }else{
                continue;
            }
            
        }
        
    }

    return true;
    


        
}

// int main(){
//     vector<vector<char>> board = {
//         {'5','3','.','.','7','.','.','.','.'},
//     {'6','.','.','1','9','5','.','.','.'},
//     {'.','9','8','.','.','.','.','6','.'},
//     {'8','.','.','.','6','.','.','.','3'},
//     {'4','.','.','8','.','3','.','.','1'},
//     {'7','.','.','.','2','.','.','.','6'},
//     {'.','6','.','.','.','.','2','8','.'},
//     {'.','.','.','4','1','9','.','.','5'},
//     {'.','.','.','.','8','.','.','7','9'}};



//     bool ans = isValidSudoku(board);

//     cout << ans << endl;
// }