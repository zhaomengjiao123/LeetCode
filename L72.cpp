// 编辑距离
// 将A 单词转换为B单词所需要的最少的操作数<
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 所有的操作可以简化成三个操作：从A中插入  从B中插入 修改A的一个单词
int minDistance(string word1, string word2) {
    // dp i j 表示A的前i个字母和B的前j个 字母 之间的编辑距离
    int n = word1.length();
    int m = word2.length();
    // 如果有一个字符串为空
    if (n*m==0)
    {
        return n+m; // 那么变换操作的步骤数就是另个字符串的长度
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    // 边界状态初始化
    for (int i = 0; i < n+1; i++)
    {
        dp[i][0]=i;
    }
    for (int j = 0; j < m+1; j++)
    {
        dp[0][j]=j;
    }
    // 计算所有的dp值
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            int left = dp[i-1][j]+1;
            int down = dp[i][j-1]+1;
            int left_down = dp[i-1][j-1];
            if (word1[i-1]!=word2[j-1])
            {
                // 如果不同的话，就要多修改一次
                left_down = left_down + 1;
            }
            dp[i][j]=min(left, min(down, left_down));
            
        }
        
    }
    return dp[n][m];
    
    

    



}