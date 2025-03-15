// 最长递增子序列


#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

// 思路：动态规划
// dp[i] 以nums[i]为结尾的最长递增子序列的长度
// dp[i]=dp[j]+1 或者 nums[i]>nums[j]  需要找一下这个j
int getAns(vector<int>& nums){
    int n = nums.size();
    if (n==0)
    {
        /* code */
        return 0;
    }
    
    vector<int> dp(n+1);
    dp[0]=1;
    int ans = 1; //只有一个元素的时候
    for (int i = 1; i < n; i++)
    {
        // 找到符合要求的j
        dp[i]=1; // 初始值  ：只有自己
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
    



}

int main(){
    vector<int> nums={10,9,2,5,3,7,101,18};
    int ans = getAns(nums);
    cout<<ans<<endl;
    
}