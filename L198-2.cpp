// 打家劫舍
// 不能偷窃相邻的房屋
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//dp[i]为偷窃i号房屋时能偷到的最大的金额
// dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
// 初始条件 
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=nums[0];
    if(n==1){
        return dp[n];
    }
    for(int i=2;i<=n;i++){
        dp[i]=max(nums[i-1]+dp[i-2], dp[i-1]);
    }
    return dp[n];

}

int main(){
    vector<int> nums= {2,7,9,3,1};
    int ans = rob(nums);
    cout<<ans<<endl;
}
