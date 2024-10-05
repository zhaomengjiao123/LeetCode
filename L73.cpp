/**
 * @file L73.cpp 矩阵置零
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 如果矩阵中某个元素为0，就把他所在的行列的所有元素都设为0 使用原地算法
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_set>
using namespace std;


void setZeroes(vector<vector<int>>& matrix) {
    // 思路 如果检测都一个0 ，上下左右四个方向扩展 置0
    // 有一个问题，怎么判断读取到的0是之前自己变得，还是本来有的？
    // 复制矩阵（不满足原地规则
    // 先获取所有0的位置，再修改
    unordered_set<int> rows;
    unordered_set<int> cols;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j]==0)
            {
                // 行标记
                if (!rows.count(i))
                {
                    /* code */
                     rows.insert(i);
                }
                if (!cols.count(j))
                {
                    cols.insert(j);
                }  
            }
            
        }
        
    }
    for (auto it = rows.begin(); it!=rows.end();it++)
    {
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[*it][i]=0;
        }
        
        
    }
     for (auto it = cols.begin(); it!=cols.end();it++)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][*it]=0;
        }
        
        
    }
    
    
    
    

}