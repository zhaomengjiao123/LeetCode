/**
 * @file L189.cpp 打家劫舍
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// 给定一个数组  找出最大的和  所计算的因子不能有相邻的
// 动态规划


/**
 * 假设 ｆｉ　表示以ｎｕｍｉ　为结尾的所选取的数字的最大值
 * j < i  fi = fj + num i j!=i-1
 * 偷 i-1 或者 i-2 + num i
 * 
 * @param nums 
 * @return int 
 */
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n==0)
    {
        /* code */
        // 判断特殊情况
        return 0;
    }
    
    vector<int> f(n);
    f[0]=nums[0];
    if (n==1)
    {
        /* code */
        return f[0];
    }
    
    // 注意 f1 不是 num1 应该是前两个数中最大的哪个
    f[1]=max(f[0], nums[1]);
    int ans = max(f[0], f[1]);
    for (int i = 2; i < n; i++)
    {
        /* code */
        // 因为给出的数字都是非负的  所以不用考虑负数
        f[i] = max(f[i-1], f[i-2]+nums[i]);
        ans = max(ans, f[i]);
        

    }
    return ans;
    


}

int main(){
    string input;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> nums;
    while (ss >> num)
    {
        /* code */
        nums.push_back(num);
    }

    int ans = rob(nums);
    cout << ans << endl;
    
}