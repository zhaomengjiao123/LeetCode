#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// dp? 
// dp[i]以当前位置为最小值的最大值的和
// dp[i] = 比nums[i]大的数  
int getAns(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());

   
    int ans = INT_MIN;
    //那只要不是负的都行呀？
    for(int i=0;i<n;i++){
        // 若以当前值为最小值
        int tmp = nums[i]+n-i;

        ans = max(ans, tmp);

        
    }
    return ans;

}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> nums;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            nums.push_back(a);
            // cout<<"a:"<<a<<" ";
        }
        cout<<endl;
        int ans = getAns(nums);
        cout<<ans<<endl;

        
    }
   
}