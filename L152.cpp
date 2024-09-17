/**
 * @file L152.cpp 找到数组中乘积最大的子数组
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


// 动态规划  
// 这样做错误的  不满足最优子结构
// 状态转移方程 错了  当前位置的最优解并不是一定由前一个位置的最优解转移得到的
// int maxProduct(vector<int>& nums) {
//     /**
//      * 以 fi 表示 nums i结尾的非空子数组的最大乘积
//      * fi -1 是负数 num i <=0 fi =fi-1 * nums i
//      * fi-1 > 0  num i >0 
//      * fi-1 =0 fi =num i
//      * 
//      */
//     int n = nums.size();
//     vector<int> f(n);
//     f[0]=nums[0];
//     int ans = f[0];
//     for (int i = 1; i < n; i++)
//     {
//         /* code */
//         if (f[i-1]>0 && nums[i]>0)
//         {
//             /* code */
//             f[i] = f[i-1] * nums[i];
//         }else if ((f[i-1]<0||f[i-1]==0)&&(nums[i]<0||nums[i]==0))
//         {
//             /* code */
//             f[i] = f[i-1] * nums[i];
//         }else if ((f[i-1]<0||f[i-1]==0)&&(nums[i]>0))
//         {
//             /* code */
//             f[i] = nums[i];
//         }else if (f[i-1]>0 && (nums[i]==0||nums[i]<0))
//         {
//             /* code */
//             f[i] =nums[i];
//         } 
//         ans = max(ans, f[i]);
  
//     }
//     return ans;
    

// }

int maxProduct(vector<int>& nums) {
    /**
     * 以 fi 表示 nums i结尾的非空子数组的最大乘积
     * fi -1 是负数 num i <=0 fi =fi-1 * nums i
     * fi-1 > 0  num i >0 
     * fi-1 =0 fi =num i
     * 还需要维护一个乘积最小的非空子数组
     */
    int n = nums.size();
    // 不能初始化为0  不然乘法  乘0=0
    vector<long> f(nums.begin(), nums.end());
    vector<long> minF(nums.begin(), nums.end());

    f[0]=nums[0];
    minF[0] = nums[0];
    long ans = f[0];
    for (int i = 1; i < n; i++)
    {
        f[i]= max(f[i-1]*nums[i], max(minF[i-1]*nums[i], (long)nums[i]));
        minF[i]=min(f[i-1]*nums[i], min(minF[i-1]*nums[i], (long)nums[i]));
        // 维护当前最大乘积
        if (minF[i] < INT_MIN)
        {
            /* code */
            minF[i] = nums[i];
        }

        ans = max(ans, f[i]);

        
  
    }
    return ans;
    

}


int main(){
    vector<int> nums;

    string s;
    getline(cin, s);

    int number;
    stringstream ss(s);
    while (ss >> number)
    {
        /* code */
        nums.push_back(number);

    }

    int ans = maxProduct(nums);

    cout << ans << endl;
    

}