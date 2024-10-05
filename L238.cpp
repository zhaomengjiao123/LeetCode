/**
 * @file L238.cpp 数组中 某数出自己以外的乘积
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 不可以用除法
// 前缀 后缀？
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    // 前缀存储num[i]以及之前的的乘积，after[i]存储从后往前的乘积
    int n=nums.size();
    vector<int> after(n);
    vector<int> before(n);
    vector<int> ans(n);
    if (n==2)
    {
        ans[0]=nums[1];
        ans[1]=nums[0];
        return ans;
    }
    // 初始化
    // nums i代表前i个数的乘积
    before[0]=nums[0];
    after[0]=nums[n-1];
    for (int i = 1; i < n; i++)
    {
        after[i]=after[i-1]*nums[n-1-i];
        before[i]=before[i-1]*nums[i];
    }
    ans[0]=after[n-2];
    for (int i = 1; i < n-1; i++)
    {
        ans[i]=before[i-1]*after[n-1-i-1];
    }
    ans[n-1]=before[n-2];
    return ans;
}

int main(){
    int num;
    string s;
    getline(cin,s);
    vector<int> nums;
    stringstream ss(s);
    while (ss>>num)
    {
        nums.push_back(num);
        
    }
    vector<int> ans = productExceptSelf(nums);
    for (int i=0;i<ans.size();i++)
    {
        /* code */
        cout << ans[i] << " ";
    }
    

    

}