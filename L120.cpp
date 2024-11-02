// 三角形最小路径和
// 给定一个三角形，找到自顶向下的最小的路径和
// 智能移动到 下一行相邻节点

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;


// 自己的思路：动态规划
// f i j :  坐标i j 最小的路径和  答案是 f[i-1][j]
// fi j  =min(fi-1,j, fi-1,j-1)+nums i ,j
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    if (n==1)
    {
        return triangle[0][0];
    }
    int mx_m = triangle[n-1].size();
    vector<vector<int>> f(n, vector<int>(mx_m));
    f[0][0]  = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j==0)
            {
                f[i][j]=f[i-1][j]+triangle[i][j];
                
            }else if(j==triangle[i-1].size()){
                f[i][j]=f[i-1][j-1]+triangle[i][j];
            }else{
                f[i][j]=min(f[i-1][j],f[i-1][j-1])+triangle[i][j];

            }
            cout<<f[i][j]<<endl;

            cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
            
        }
        
    }
    // 找到最后一行的最小值
    int ans = *min_element(f[n-1].begin(),f[n-1].end());

    return ans;
    
    
    
        
}

int main(){
    vector<vector<int>> nums = {
        {2},{3,4},{6,5,7},{4,1,8,3}
    };
    int ans = minimumTotal(nums);
    cout <<ans << endl;
}