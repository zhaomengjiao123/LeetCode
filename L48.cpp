/**
 * @file L48.cpp 旋转图像
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 原地旋转 矩阵
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

// 行-> 列 并且第一行是最后一列
void rotate(vector<vector<int>>& matrix) {
    // 向右转转90度
    // 先每一列倒排，然后沿y=x交换
    int i=0,j=matrix.size()-1;
    while (i<j)
    {
        for (int k = 0; k < matrix[0].size(); k++)
        {
            swap(matrix[i][k], matrix[j][k]);
        }
        i++;
        j--;
        
    }

    // 沿对角线交换  只需要遍历对角线下面的这一部分数就可以了
    for (int x = 1; x < matrix.size(); x++)
    {
        for (int y = 0; y < x; y++)
        {
           if (x!=y)
           {
            swap(matrix[x][y], matrix[y][x]);
           }
           
        }
        
    }
    
    

}