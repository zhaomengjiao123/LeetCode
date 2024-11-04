// 环形子数组的最大和

// num 的非空子数组的最大可能和
// 子数组只能包含某个元素一次


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

// 思路：动态规划  和求最大子数组和差不多，只不过这次跳出循环的条件是  循环一圈

// 最多只包含缓冲区的元素一次
// 有两种情况，要么这个子数组在数组中实在正序的，和最大子数组的和一样，是在数组的中间
// 要么 这个子数组就是占据头部一块和尾部一块
// 第一种情况就是  普通的求最大子数组的和 第二种可以这么想：求出最小的子数组的和，总的和-最小的，剩下的就是占据头尾部分最大的和了
int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    if (n==1)
    {
        return nums[0];
    }
    // 最大的子数组的和  正常数组情况下
    vector<int> f_max(n);
    f_max[0]=nums[0];
    int maxRes = f_max[0];
    // 最小的子数组的和  正常数组情况下
    vector<int> f_min(n);
    f_min[0]=nums[0];
    int minRes = f_min[0];

    int sum = nums[0]; // 求整个数组的和
    for (int i = 1; i < n; i++)
    {
        f_max[i] = max(f_max[i-1]+nums[i], nums[i]);
        f_min[i] = min(f_min[i-1]+nums[i],nums[i]);
        maxRes = max(maxRes, f_max[i]);
        minRes = min(minRes, f_min[i]);
        sum = sum + nums[i];
    }

    // 要考虑一种情况是，整个数组全是负值，那么 minRes 实际会是整个数组的和
    if (maxRes<0)
    {
        return maxRes;
    }else{
        return max(maxRes, sum-minRes);
    }
    
    
    
    
    
        
}

int main(){
    vector<int> nums = {1,-2,3,-2};
    int ans = maxSubarraySumCircular(nums);
    cout << ans << endl;
}