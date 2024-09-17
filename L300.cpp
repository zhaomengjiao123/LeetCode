/**
 * @file L300.cpp 最长递增子序列
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * @brief 动态规划
 * 
 * @param nums 
 * @return int 
 */
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    /**
     * @brief 动态规划的思路  fi 表示以 num i 为结尾的最大上升子序列的长度
     * f i-1 就是以  num i-1 为结尾的上升子序列的长度
     * 状态转移：只要  num i 大于 f i-1 中最大的值，那么就可以接在 f i-1 这个序列的后面
     * 初始化： f[0] = 1 
     * 结果：找到最大值
     * 
     */
    vector<int> f(nums.size());
    if(nums.size()==0){
        return 0;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        f[i] = 1;
        // 查看之前的值，只要有一个比当前的值小，那么 fi 的长度就可以+1
        /* code */
        for (int j = 0; j < i; j++)
        {
            /* code */
            if(nums[j]<nums[i]){
                // 同时，为了找到最大的上升子序列，还要看 dp i 和 dp j哪个大
                f[i] = max(f[i], f[j]+1); // f[j]+1 是因为当前的值更大
            }
        }
    }

    return *max_element(f.begin(), f.end());
}

int main(){
    string line;
    vector<int> nums;

    getline(cin, line);

    stringstream ss(line);

    int num;
    while (ss >> num)
    {
        /* code */
        nums.push_back(num);
    }

    int ans = lengthOfLIS(nums);

    cout << ans << endl;
    
}