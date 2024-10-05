/**
 * @file L54.cpp 螺旋矩阵
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 按照顺时针螺旋顺序返回矩阵的元素
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // 四个指针
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    // 定义四个指针
    int top = 0;
    int bottom = m-1;
    int right = n-1;
    int left = 0;
    while (top<=bottom && left <= right)
    {
        for (int i=left; i<=right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <=bottom ; i++)
        {
            /* code */
            ans.push_back(matrix[i][right]);
        }
        right--;
        // 重新判断一次
        if (top<=bottom)
        {
             for (int i = right; i >= left; i--)
        {
            /* code */
            ans.push_back(matrix[bottom][i]);
        }
            
        }
        
        bottom--;
        if (left<=right)
        {
             for (int i = bottom; i >= top ; i--)
        {
            /* code */
            ans.push_back(matrix[i][left]);
        }
        }
        
       
        left++;   
    }
    return ans;
}