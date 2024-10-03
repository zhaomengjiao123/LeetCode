/**
 * @file L34.cpp 在排序数组中  找到目标值的开始位置和结束位置
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 二分 但是找到中间位置的时候需要严格大于和小于？
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;



vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans = {-1,-1};
    // 判断是空数组的

    int n = nums.size();
    if (n==0)
    {
        return ans;
    }
    // 判断1个数的情况
    if (n==1)
    {
        if (target==nums[0])
        {
            ans[0]=0;
            ans[1]=0;
            return ans;
        }else 
        {
            return ans;
        }
        
        
    }
    
    

    int left=0, right = n-1;
    while (left<=right)
    {
        int mid=(right-left)/2+left;
        if (nums[mid]>target)
        {
            // 在一定在左边
            right=mid-1;
        }else if (nums[mid]<target)
        {
            // 一定在右边
            left=mid+1;
        }else{
            // 相等的情况，1.当前是第一个 2.当前是最后一个 3. 当前是中间一个
            // 初始化左右边界位置
            int l=mid, r=mid;
            while (l>left&&nums[l]==target)
            {
                //向左探索
                l--;
            }
            while (r<right&&nums[r]==target)
            {
                // 向右探索
                r++;
            }
            // 因为最终的l和r和真实的边界总是差一 不一定单独判断
            if (nums[l]!=target)
            {
                l=l+1;
            }
            if (nums[r]!=target)
            {
                r=r-1;
            }
            
            
            ans[0]=l;
            ans[1]=r;
            return ans;
        } 
    }
    return ans;
    


}