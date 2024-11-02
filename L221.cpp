// 最大正方形  找到只包含0 1的二位矩阵中  只包含1的最大正方形  返回面积

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;


// 动态规划？
// f i j 表示 以i j为右下角  23的最大正方形的面积
// f i j = matrix[i]这一行全是1 && matrix[j]也一行也全是1 f ij = f[i-1][j-1]+

int maximalSquare(vector<vector<char>>& matrix) {
    // 判断特殊情况
    if (matrix.size()==0||matrix[0].size()==0)
    {
        return 0;
    }
    int maxSide = 0;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols));
    // 遍历每个位置
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j]=='1')
            {
                // 如果是第一行或者第一列  那么大小只能是1
                if (i==0||j==0)
                {
                    dp[i][j]=1;
                }else{
                    // 状态转移 dp i j代表以i j 为右下角的正方形
                    // 查看它的左边上边右斜上面
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
                // 更新最大边长
                maxSide = max(maxSide, dp[i][j]);
                
            }
            
        }


        
    }
    return maxSide*maxSide;

    
    
        
}