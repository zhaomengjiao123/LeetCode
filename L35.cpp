/**
 * @file L35.cpp 使用二分法搜索插入的位置 log(n)复杂度
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 二分法 左右指针，计算中间位置，与目标值对比，然后一动左指针，或者移动有指针
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;


int searchInsert(vector<int>& nums, int target) {
    int n=nums.size();
    int l=0, r=n-1;
    int ans=n;
   
    // 当左右指针不重合的时候
    while (l<=r)
    {
         // 计算中间值
        int mid = (r-l/2)+l ;// l相当于目前的偏移值
        if (nums[mid]>=target)
        {
            // 说明目标值一定在左半部分
            ans = mid;

            r=mid-1; 
        }else{
            // 一定在右半部分
            l=mid+1;
        }  
    }
    return ans;
    
    

}

int main(){
    int target;
    string s;
    vector<int> nums;
    getline(cin, s);

    cin>>target;
    stringstream ss(s);
    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }
    int ans = searchInsert(nums, target);

    cout << ans <<endl;
    
}