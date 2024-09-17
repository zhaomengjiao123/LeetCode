/**
 * @file L560.cpp 找到 和 为 k 的子数组
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
#include<string>
#include<algorithm>
#include<unordered_map>
#include<sstream>
using namespace std;


// 前缀和和哈希优化
int subarraySum(vector<int>& nums, int k) {
    // 创建哈希表  键是前缀和 以 numi为结尾的串的和  值为出现的次数
    unordered_map<int, int> mp; 
    mp[0]=1;
    int count = 0, pre=0;
    for (auto &x:nums)
    {
        /* code */
        // 前缀和就是一直累加
        pre = pre +x;
        // 更新所找到的和为k的子串
        if (mp.find(pre-k)!=mp.end())
        {
            /* code */
            // 能找到的话
            count = count + mp[pre-k];
        }
        // 更新当前和的次数
        mp[pre]++;
    }
    return count;
}

int main(){
    vector<int> nums;
    string input;

    getline(cin, input);

    int k;
    cin >> k;

    int number;
    stringstream ss(input);

    while (ss >> number)
    {
        /* code */
        nums.push_back(number);
    }
    int ans = subarraySum(nums, k);

    cout << ans <<endl;
    



}