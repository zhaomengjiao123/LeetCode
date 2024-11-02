// 不同路径：给定一个矩阵，从左上角移动到右下角 每次只能向右或者向下用移动一步
// 不能走有障碍物的方格  找到路径的数量

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;


// 动态规划  fij表示到 ij的路径的数量
// 
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> f(n,vector<int>(m));
    // 初始化第一行和第一列
    // 标记本行是否有障碍
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (obstacleGrid[i][0]!=1&&!flag)
        {
             f[i][0]=1;
        }else{
            flag=true;
            f[i][0]=0;
        }
        
       
    }
// 标记本列是否有障碍
    flag = false;
    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[0][i]!=1&&!flag)
        {
             f[0][i]=1;
        }else{
            flag=true;
            f[0][i]=0;
        }
        
       
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (obstacleGrid[i][j]!=1)// 可通行
            {
                f[i][j]=f[i-1][j]+f[i][j-1];
            }else{
                f[i][j]=0;
            }
            
        }
        
    }

    return f[n-1][m-1];
    

    
        
}

int main(){
    vector<vector<int>> nums = {
        {0,0,0},{0,1,0},{0,0,0}
    };

    int ans = uniquePathsWithObstacles(nums);
    cout << ans << endl;
}