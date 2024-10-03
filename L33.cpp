/**
 * @file L33.cpp 搜索旋转排序数组
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 数组在某个未知的下标处开始旋转
// 局部有序，就在有序的那部分找？
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (!n)
    {
        return -1;
    }
    // 判断特殊情况， 只有一个数的时候  返回下标
    if (n==1)
    {
        return nums[0]==target? 0: -1;
    }
    int l=0, r=n-1;
    while (l<=r)
    {
        int mid = (r-l)/2 + l;
        if (nums[mid]==target)
        {
            return mid;
        }
        // 假设左边有序
        if (nums[0]<=nums[mid])
        {
            // 查看目标值是不是在当前这个范围里面，在这个部分做二分
            if (nums[0]<=target && target<nums[mid])
            {
                // 算是在左边
                r = mid-1;
            }else{
                // 在右边
                l=mid+1;
            }
            
        }else{
            // 左边不是有序的，但是右边也不一定是有序的，但是mid的一边一定是有个有序地
            // 看下目标值是不是在右边
            if (nums[mid]<target && target <= nums[n-1])
            {
                // 在右边
                l = mid+1;
                
            }else
            {
                /* code */
                r=mid-1;
            }
            
            
        }
        
        
    }
    return -1;
}

int main(){
   
    string s;
    vector<int> nums;

    getline(cin, s);
    stringstream ss(s);
    int num;

    int target;
    cin>>target;

    while (ss>>num)
    {
        nums.push_back(num);
    }
    int ans = search(nums, target);
    cout << ans << endl;
    
}