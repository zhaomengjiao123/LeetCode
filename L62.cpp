// 每次只能向右或者向下
// 有多少种不同的路径？
// 走到最右的路径数+走到最下的路径数
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


// f[i][j]走到i,j 的路径总数，f[0][0]=0,f[1][0]向下走一步=1 f[0][1]向右走一步=1
int uniquePaths(int m, int n) {
    vector<vector<int>> f(m+1,vector<int>(n+1));
    f[0][0]=1;
    f[1][0]=1;
    f[0][1]=1;
    int i = 1,j=1;
    for (int k = 2; k < m; k++)
    {
       f[k][0]=1;
    }
    for (int k = 2; k < n; k++)
    {
       f[0][k]=1;
    }
    
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1];
        }
        
    }
    
    return f[m-1][n-1];
}

int main(){
    int m,n;
    cin>>m >>n;
    int ans = uniquePaths(m,n);
    cout << ans <<endl;
}