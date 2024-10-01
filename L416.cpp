/**
 * @file L416.cpp 分割等和子集
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 只包含正整数的非空数组，要求判断是否可以分成和相等的两个子集
// 动态规划？
// 即 找到数组中的一些数字，使其和=数组和的一半
// dp ij 表示 从0-i的数字中是否可以找到和为j的子集？
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

bool canPartition(vector<int>& nums){
    // n < 2的话是绝对不可以分成两个子集的
    int n = nums.size();
    if (n<2)
    {
        return false;
    }
    // 如果sum是奇数 也绝对不可以
    // 另外，如果数组中的最大值>sum/2，那么也绝对不可能划分
    int sum = 0;
    int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + nums[i];
        maxNum = max(maxNum, nums[i]);
    }
    if (sum%2!=0 || maxNum>sum/2)
    {
        return false;
    }
    int target = sum/2;
    vector<vector<int>> dp(n, vector<int>(target+1,0));
    // 初始化，如果和为0 ，那么可以不选任何数，所以是true
    for (int i = 0; i < n; i++)
    {
        dp[i][0]=1;
    }
    dp[0][nums[0]]=true; // 选自己
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < target+1 ; j++)
        {
            if (j>=nums[i])
            {
                //选numsi
                dp[i][j]=max(dp[i-1][j-nums[i]],dp[i-1][j]);

                // 不选numsi
            }
            if (j<nums[i])
            {
                // 这种情况下肯定不选nums i
                dp[i][j]=dp[i-1][j];
            }
            
            
        }
        
    }
    return dp[n-1][target];
}

int main(){
    string s;
    vector<int> nums;

    getline(cin, s);
    stringstream ss(s);
    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }
    bool ans = canPartition(nums);
    cout << ans << endl;
    
}