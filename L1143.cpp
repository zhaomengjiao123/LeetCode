// 最长的公共子序列
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

// fi j 代表较短的那个字符串t1 i 和  t2 j结尾的公共子串的长度  ij代表长度
// 因此坐标就是 i-1  j-1
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();;
    int m = text2.size();
    vector<vector<int>> f(n+1, vector<int>(m+1));
    // 初始化
    f[0][0]=0;
    f[1][0]=0;
    f[0][1]=0;
    for (int i = 1; i <= n; i++)
    {
        char ch1 = text1.at(i-1);
        for (int j = 1; j <= m; j++)
        {
            char ch2 = text2.at(j-1);
            // 只有这两个相等了 才是 相同子串
            if (ch1 == ch2)
            {
                f[i][j]=f[i-1][j-1]+1;
            }else{
                //// 否则的话值就等于前一个
                f[i][j]=max(f[i][j-1],f[i-1][j]);
            }
            

        }
        
    }
    return f[n][m];
    



}