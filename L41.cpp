/**
 * @file L41.cpp 缺失的第一个 正数
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/**
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
using namespace std;

//自己的思路，创建一个1~n的哈希表，然后遍历一遍数组填充哈希表，存在就标记，最后找到哈希表中第一个值为0
// 也就是出现次数为0的键
// int firstMissingPositive(vector<int>& nums) {
//     int n = nums.size();
//     int maxNum = *max_element(nums.begin(),nums.end());
//     cout << maxNum <<endl;
//     unordered_map<int, int> hash;
//     for (int i = 1; i <= maxNum ; i++)
//     {
//         hash[i]=0;
//     }
//     for (int i = 0; i < n; i++)
//     {
//        if (nums[i]>0)
//        {
//         if (hash.count(nums[i])!=0)
//         {
//             hash[nums[i]]++;
//             cout << nums[i] << " "<<hash[nums[i]]<<endl;

//         }
        
//        }
//     }
//     for (auto it=hash.begin();it!=hash.end();it++)
//     {
//         cout<<it->first<<endl;
//         if (it->second==0)
//         {
//            return it->first;
//         }
        
//     }
//     // 最大值都在数组中
//     return max(maxNum,0)+1;
// }
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int maxNum = *max_element(nums.begin(),nums.end());
    int ans = 0;
    // 检查1是否存在
    bool flag = false;
    // 先排序
    sort(nums.begin(),nums.end());
    for (int i = 0; i < n; i++)
    {
        if (nums[i]>0)
        {
            if (nums[i]==1)
            {
                flag=true;
            }
            if (flag)
            {
                // 替换为最小的正整数
                // 必须是连续的，遇到不连续的就返回  同时考虑重复的情形
                if (ans+1!=nums[i]&&ans!=nums[i])
                {
                    return ans+1;
                    
                }else{
                    ans = nums[i];
                }
            }else{
                // 否则直接返回1
                return 1;
            }
            
            
        }
        
    }
    return max(nums[n-1],0)+1;
    
}

int main(){
    string s;
    getline(cin,s);

    vector<int> nums;

    stringstream ss(s);
    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }
    int ans = firstMissingPositive(nums);
    cout << ans <<endl;
    
}