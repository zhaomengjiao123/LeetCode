// 最长回文子串
// 动态规划
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// fi,j 表示 第i到j 是回文串
// fi,j = p(i+1,j-1)&& si==sj  因为只有两边的字母是一样的才能组成回文串
string longestPalindrome(string s) {
    int n = s.size();
    // 如果长度小于2  直接返回
    if (n < 2)
    {
        return s;
    }
    int maxLen = 1;
    int begin = 0;
    
    vector<vector<int>> f(n, vector<int>(n));
    // 所有长度为1  的 子串  都是回文串
    for (int i = 0; i < n; i++)
    {
        f[i][i]=true; 
    }
    // 需要枚举子串的长度
    for (int L = 2; L <= n; L++)
    {
        // 枚举 左边界
        for (int i = 0; i < n; i++)
        {
            // 确定右边界 L+I-1 = J
            int j = L + i -1;
            // 如果右边界越界，就可以退出当前循环
            if (j>=n)
            {
                break;
            }
            // 状态转移  两头 的字母需要一致
            if (s[i]!=s[j])
            {
                f[i][j]=false;
            }else{
                // 如果两个相隔1 2 0  
                if (j-i<3)
                {
                    f[i][j]=true;
                }else{
                    // 否则的话  等于 两边往里 扩一个
                    f[i][j]=f[i+1][j-1];
                }
                

            }
            if (f[i][j]&&j-i+1>maxLen)
            {
                maxLen = j-i+1;
                begin=i;
                
            }
            
            
            
        }
        
    }
    return s.substr(begin, maxLen);
}