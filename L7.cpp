// 找出和为0 的三个数  不重复的三元组

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


// 二分
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    // 先给数组排序
    int n = nums.size();
    if (n<3)
    {
        return ans;
    }
    sort(nums.begin(),nums.end());
    // 从第一个数开始找
    for (int first = 0; first < n; first++)
    {
        // 不能重复
        if (first>0 && nums[first]==nums[first-1])
        {
            // 相同的直接跳过
            continue;
        }
        // 开始找第二个数
        int target = -nums[first];
        int third = n-1;
        for (int second = first+1; second < n; second++)
        {
            // 第二个数不能重复
            if (second>first+1 && nums[second]==nums[second-1])
            {
                continue;
            }
            while (second<third && nums[second]+nums[third]>target)
            {
                // 数太大了  第三个数也更小
                third--;
            }
            if (second==third)
            {
                // 找不到了 放弃
                break;
            }
            if (second<third && nums[second]+nums[third]==target)
            {
                // 找到了三元组
                ans.push_back({-target, nums[second],nums[third]});
            }
            
            
            
            
        }
        
        
        
    }

    return ans;
    
    


}