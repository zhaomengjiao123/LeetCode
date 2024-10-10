/**
 * @file L31.cpp 下一个排列
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

void nextPermutation(vector<int>& nums) {

    int i =nums.size()-1;
    // 首先从后往前找到 a[i]<a[i+1]
    // 这意味着 i+1 到 n一定是降序排列的
    // 较小的数就是 a[i]
    // 较大的数 就是从后向前找的第一个a[j]>a[i]
    // 一直升序一直走
    while (i>=0 && nums[i]>=nums[i+1])
    {
        i--;
    }
    if (i>=0)
    {
        // 找到较小数了，开始找较大数
        int j = nums.size()-1;
        while (j>=0&&nums[i]>=nums[j])
        {
            j--;
        }
        // 找到第一个较大数
        swap(nums[i],nums[j]);
        
    }
    // 倒序  i-n
    reverse(nums.begin()+i+1,nums.end());
}