/**
 * @file L198.cpp实际上是 189  轮转数组  数组向右轮转k个位置
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 空间复杂度0 (1)?
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

// 直接新数组，谢谢
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    // 非空数组
    // 如果刚好是倍数，那么相当于原来的
    if (k%n==0)
    {
        return;
    }
    k = k % n ; // 更新，不要做没有用的轮转操作
    // 保证k<n
   // 每个元素的新位置 是 i+k%n
   vector<int> newArr(n);
   for (int i = 0; i < n; i++)
   {
    newArr[(i+k)%n]=nums[i];
   }
   nums.assign(newArr.begin(),newArr.end());
}