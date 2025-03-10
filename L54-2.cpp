// 螺旋矩阵
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 思路；模拟
        // 定义四个指针
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int left = 0;
        int right = m-1;
        int bottom = n-1;
        vector<int> ans;
        // 如果把每次的增减都放在每次遍历完了之后，那么就需要 每次都  判断边界情况
        while (top<=bottom && left<=right)
        {
            // 先遍历上
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            if(top>bottom||left>right){
                break;
            }
            // 遍历右边
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
             if(top>bottom||left>right){
                break;
            }
            // 再判断一遍边界，防止溢出
                // 遍历底部
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                 if(top>bottom||left>right){
                break;
            }
                // 遍历左边
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                 if(top>bottom||left>right){
                break;
            }
            
        } 
        return ans; 
}


int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    for(auto num : ans){
        cout << num << " ";
    }
}