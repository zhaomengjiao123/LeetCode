/**
 * @file L53.cpp 最大子数组的和
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/**
 * 动态规划
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

/**
 * @brief  fi 表示 以 num i为结尾的最大子数组的和，那么f i-1 就是以nums i-1 为结尾的最大子数组的和
 * 因此 fi = num i 或者  fi = f i-1 + num i  如果  f i-1 < 0就没必要加了
 * 
 * @param nums 
 * @return int 
 */
int maxSubArray(vector<int>& nums) {
    // 初始化容器大小
    vector<int> f(nums.size());
    // 初始化第一个值
    f[0] =nums[0];
    // 初始化最大值 f0
    int ans = f[0];
    // 开始遍历 从  1  开始
    for (int i = 1; i < nums.size(); i++)
    {
        /* code */
        // 以当前数值为结尾的子数组的和
        // 判断以前一个数值为结尾的子数组值不值得 加上
        f[i] = max(f[i-1],0) + nums[i];
        if (f[i] > ans)
        {
            /* code */
            // 更新最大值
            ans = f[i];
        }
        
    }
    // 那么ｆｉ中最大的就是最大的子数组的和了
    // ranges::max()  
    return ans;
}

int main(){
    vector<int> nums;
    string line;

    getline(cin, line);

    stringstream ss(line);

    int num;

    while (ss >> num)
    {
        /* code */
        nums.push_back(num);

    }

    int ans = maxSubArray(nums);

    cout << ans << endl;
    

    
}