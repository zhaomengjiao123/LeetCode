// 交错字符串 验证 s3 是不是 s1 s2交错

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


// 思路：动态规划 f [i, j] 代表前s1 前i个字符和s2前j个字符能组成 s3 前（i+j）哥字符
// 为true的条件是：如果s1(i-1)==s3[p] 那还得是 f[i-1][j] 也要是可以构成的才行
// 同理：f[i][j-1] 以及  s2[j-1]==s3[p] 也可以构成的


bool isInterleave(string s1, string s2, string s3) {
    vector<vector<int>> f(s1.size()+1, vector<int>(s2.size()+1, false));
    int n = s1.size(), m =s2.size(), t = s3.size();
    // 如果长度不匹配的话，一定是不行的
    if(n+m!=t){
        return false;
    }
    
    // 初始化 OO  这个是边界
    f[0][0]=true;
    // 初始化边界条件  查看单s1 是否匹配？
    for (int i = 1; i <= n; i++)
    {
        f[i][0]=f[i-1][0] && (s1[i-1]==s3[i-1]);
    }
    for (int i = 1; i <= m; i++)
    {
        f[0][i]=f[0][i-1] && (s2[i-1]==s3[i-1]);
    }
    
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // 定位需要比较的s3的位置
            int p = i+j-1;
            bool op1 = false, op2 = false;
            if (i>0)
            {
                op1 = f[i-1][j] && (s1[i-1]==s3[p]);
            }
            if (j>0)
            {
                op2 = f[i][j-1] && (s2[j-1]==s3[p]);
            }
            f[i][j] = op1 || op2;
            
            
        }
        
    }

    return f[n][m];
    

        
}

int main(){
    string s1, s2,s3;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    bool ans = isInterleave(s1,s2,s3);
    cout << ans <<endl;

}