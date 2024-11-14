// 数组中找到与给定的target 最接近的三数之和
// 每个数只能用一次

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;

// 按照三数之和的思路，二分查找，每次更细 最小差值和最小和
int threeSumClosest(vector<int>& nums, int target) {
    // 先排序
    sort(nums.begin(),nums.end());
    int sub = INT_MAX;
    int ans = 0;
    int n = nums.size();
    for (int first = 0; first < n; first++)
    {
        // 确定第一个数 不能重复  但是这个题里面是可以重复的
        // if (first>0&&nums[first]==nums[first-1])
        // {
        //     continue;
        // }
        for (int second = first+1, third = n-1; second < third;)
        {
            // 计算当前的和
            int sum = nums[first]+nums[second]+nums[third];
            // 如果相等了 直接返回
            if (sum==target)
            {
                return sum;
            }
            
            // 查看与target 的差值  是否需要更新
            if (abs(sub)>abs(target-sum))
            {
                sub = abs(target-sum);
                ans = sum;
            }
            // 如果比目标值大  third 左移
            if (sum>target)
            {
                third--;
            }
            // 如果比目标值小 second 右移
            if (sum<target)
            {
                second++;
            }
            
            

            
        }
        
        
    }

    return ans;
    

        
}

int main(){
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    int ans = threeSumClosest(nums, target);
    cout << ans <<endl;
}