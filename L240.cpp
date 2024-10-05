/**
 * @file L240.cpp 搜索二维矩阵
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 从左到右升序 从上到下升序
// 高效搜索  二分？不是严格升序
// 每一行的末尾值比target小的就没必要查了
// 每一列末尾值比target小的也没必要查了
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m =matrix.size();
    int n=matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        // 如果当前的数<target，我们就搜索这一列，直到发现
        // 或者比target大的数
        if (matrix[0][i]<=target)
        {
            // 搜索这一列
            for (int j = 0; j < m; j++)
            {
                if (matrix[j][i]==target)
                {
                    return true;
                }
                if (matrix[j][i]>target)
                {
                    break;
                } 
            }
            
        }else{
            break;
        }    
    }
    return false;
    
        
}