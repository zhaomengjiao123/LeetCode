/**
 * @file L153.cpp 寻找旋转排序数组中的最小值
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 旋转数组：每旋转一次就是把最后一个元素放到开头
// 找到 n 次旋转后的最小元素
// 二分，这个数组无论旋转多少次都是部分有序，而且后半部分存在最小（如果最小的不在开始）
// 和之前一样，在符合范围要求的那边找
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    if (n==1)
    {
        return nums[0];
    }
    int l=0, r=n-1;
    int ans = nums[0];
    // 先排除特殊情况  就是已经是完全升序了
    if (nums[0]<nums[n-1])
    {
        // 完全有序
        return nums[0];
    }
    if (nums[n-1]<nums[n-2])
    {
        /* code */
        return nums[n-1];
    }
    
    
    while (l<r)
    {
        int mid = (r-l)/2+l;
        
        if (nums[mid]>nums[r])
        {
            // 说明真正的最小数肯定在右边
            l=mid+1;
        }else{
            r=mid;
        } 
    }
    return nums[l];
    
    

}

int main(){
    vector<int> nums;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }

    cout << findMin(nums) << endl;
    
}