#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// 乘积最大的子数组  动态规划
// dp[i] 代表i结尾的连续子数组的最大乘积
// dp[i] = max (dp[i-1]*nums[i], nums[i]);
// 因为是乘法  素以还要注意 0 和 负数的情况
// 三种情况 dp[i-1] 为正数，0 负数
// 这三种情况分别： num i 为正数， 正数， 负数  此案呢个乘上
// 目前这个  是最大乘积，但如果目前的位置是一个负数，我们的那个钱下午那个他的前一个页数负数，并且越小越好
// 因为这样才能使乘积最大
// 所以还要维护一个最小的乘积子数组
int getAns(vector<int>& nums){
    int n = nums.size();
    // 如果不这样初始化，那么  会默认赋值为0，实际上还可能是负数
    vector<int> dp(nums.begin(),nums.end());
    vector<int> dp_min(nums.begin(), nums.end());
    int ans = dp[0];
    dp[0]=nums[0];
    dp_min[0]=nums[0];
    for(int i=1;i<n;i++){
        // 最大值可能是：前一个乘积*当前数，如果当前数是负数，那么需要前一个的 最小乘积（负数）*当前数
        // 同理最小值  也可呢能是 最大值*当前数（负数）出现的
        dp[i]=max(dp[i-1]*nums[i], max(nums[i], nums[i]*dp_min[i-1]));
        dp_min[i]=min(dp_min[i-1]*nums[i],min(nums[i], dp[i-1]*nums[i]));
        ans = max(ans, dp[i]);
        // cout<<"dp i:"<<i<<" "<<dp[i]<<" "<<ans<<endl;
    }
    return ans;
}


int main(){
    vector<int> nums = {-2,3,-4};
    int ans = getAns(nums);
    cout<<ans<<endl;
}

