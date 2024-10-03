/**
 * @file L74.cpp 搜索二维矩阵
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 如果使用二分的话，先找行 再找列
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int col = matrix[0].size();
    int left = 0, right = rows-1, targetRow = rows;
    while (left<=right)
    {
        int midRow = (right-left)/2+left;
        // 比头元素小，肯定在上一行，比尾元素大，肯定在下一行
        if (matrix[midRow][0]>target)
        {
            right = midRow-1;
        }else if (matrix[midRow][col-1]<target)
        {
            left=midRow+1;
        }else{
            // 在本行找
            int l = 0, r = col-1, targetCol = col;

            while (l<=r)
            {
                int midCol = (r-l)/2+l;
                cout << midCol << endl; 
                if (matrix[midRow][midCol]>target)
                {
                    // 在左边
                    r=midCol-1;
                }else if(matrix[midRow][midCol]<target){
                    // 在右边
                    l=midCol+1;
                }else if (matrix[midRow][midCol]==target)
                {
                    return true;
                }
            }
            return false;
            
        }
        
        
    }
}

int main(){
    int target;
    cin>>target;

    vector<vector<int>> matrix={
        {1,3,5,7},
        {10,11,16,20},
        {23,34,60,61}
    };
    
    bool ans = searchMatrix(matrix, target);
    cout << ans << endl;
    
}