/**
 * @file L322.cpp 零钱兑换
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * 动态规划
 * fi 为 i 所需的最小硬币数量
 * fi = f[i-cj] +1 cj是有的硬币的面额
 * 那么  fi = min(f[i-cj]+1, XX) 
 * 
 * @param coins 
 * @param amount 
 * @return int 
 */
int coinChange(vector<int>& coins, int amount) {
    // 方便取最小值
    int Max = amount + 1;
    vector<int> f(amount+1, Max);
    // 初始化  f[0]=0 0的最小数量就是0
    f[0]=0;
    for (int i = 1; i <= amount; i++)
    {
        /* code */
        // 遍历硬币
        for (int j = 0;j< coins.size(); j++)
        {
            /* code */
            // 找那些比当前索要的数值小的额硬币
            if (coins[j]<=i)
            {
                /* code */
                f[i]=min(f[i-coins[j]]+1, f[i]);
            }
            
        }
        
    }
    // 别忘了判断所给的 z最大值 这个也是没有意义的
    if (f[amount] > amount)
    {
        /* code */
        return -1;
    }
    
    return f[amount];
    

}

int main(){
    vector<int> nums;
    int amount;

    string s;
    getline(cin, s);

    cin >> amount;

    stringstream ss(s);
    int num;
    while (ss >> num)
    {
        /* code */
        nums.push_back(num);
    }

    int ans = coinChange(nums, amount);
    cout << ans <<endl;
    
}