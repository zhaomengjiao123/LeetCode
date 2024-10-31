// 寻找峰值
// 峰值：值严格>左右相邻的元素
// 多个峰值返回一个就行

 
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

// 伪二分
// 因为题目要求只需要找到一个峰值就可以了
// 每次把数组分为两个部分
// nums mid < nums mid+1 向右走
// nums mid < nums mid-1 向左走
// num mid > nums mid-1 && nums mid> nums mid+1 直接找到答案

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if (n==1)
    {
        return 0;
    }
    if (n==2)
    {
        return nums[0]>nums[1]?0:1;
    }
    

    int left=0, right=n-1;
    while (left<right)
    {
        int mid = (right-left)/2 +left ;
        
        if (nums[mid]<nums[mid+1])
        {
            left=mid+1;
        }else{
            right=mid;
        }
        
        
    }

    return left;
    
    
        
}

int main(){
    vector<int> nums = {1,2,1,3,5,6,4};

    int ans = findPeakElement(nums);
    cout << ans <<endl;
}