// N皇后 II
// 找到所有的可能的解  的  数量


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_set>
using namespace std;



int dfs (int n, int row, vector<int>& queens, unordered_set<int>& cols,unordered_set<int>& diag1, unordered_set<int>& diag2){
        // 检查是不是N个皇后都放完了？
        if (row==n)
        {
            // 得到一种解决方案；
            return 1;

        }else{
            int ans = 0;
            // 搜索 从第0行
            for (int i = 0; i < n; i++)
            {
                // 不能在同一列
                if (cols.find(i)!=cols.end())
                {
                    continue;
                }
                // 不能在同一个斜行  这个斜行上的数据 行-i值固定
                int subD1 = row-i;
                if (diag1.find(subD1)!=diag1.end())
                {
                    continue;
                }
                // 不能在另一个斜行
                int subD2 = row+i;
                if (diag2.find(subD2)!=diag2.end())
                {
                    continue;
                }
                // 可以加入，当前位置合法
                queens[row]=i; // row 行 放置第i个皇后
                cols.insert(i);
                diag1.insert(subD1);
                diag2.insert(subD2);
                // 搜索下一个皇后的位置
                ans = ans + dfs(n, row+1,queens, cols, diag1, diag2);
                // 回溯，将当前位置清楚
                queens[row]=-1;
                cols.erase(i);
                diag1.erase(subD1);
                diag2.erase(subD2);


                
                
            }
            return ans;

            
        }

        

}

int totalNQueens(int n) {
    // 列数 不能重复
    unordered_set<int> cols;
    // 两个斜对角线不能重复
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    // 皇后的位置  记录所在的行
    vector<int> queens(n,-1);

    int ans = dfs(n, 0, queens, cols, diag1, diag2);
    return ans;

        
}

int main(){
    int n;
    cin >> n;
    int ans = totalNQueens(n);
    cout << ans <<endl;
    

}