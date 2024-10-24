/**
 * @file L15.cpp 三数之和  和为0 的三元组
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 自己的思路：先哈希遍历一遍存储,然后双重循环！！不行
// 有重复的风险
// 排序+三重循环
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<sstream>
using namespace std;

//重复BUG
// vector<vector<int>> threeSum(vector<int>& nums) {
//     // 先排序
//     sort(nums.begin(), nums.end());
//     unordered_map<int, int> hash;
//     int n = nums.size();
//     vector<vector<int>> ans;
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         // 反过来存储
//         hash[nums[i]]=i;
//     }
//     // 双重循环
//     for (int i = 0; i < n-1; i++)
//     {
//         /* code */
//         for (int j = 1; j < n; j++)
//         {
//             /* code */
//             int tmp = nums[i]+nums[j];
//             if (hash.count(-tmp)&& hash[-tmp]>i&&hash[-tmp]>j)
//             {
//                 vector<int> t = {-tmp, nums[i], nums[j]};
//                 ans.push_back(t);

//             }
            
//         }
        
//     }
    
   
    
//     return ans;
// }
vector<vector<int>> threeSum(vector<int>& nums) {
    // 先排序
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    // 三重循环
    for (int i = 0; i < n; i++)
    {
        // 当前的数和上一次的数不能是相同，否则就会重复
        if (i>0&&nums[i]==nums[i-1])
        {
            // 跳过
            continue;
        }
        // 把 第三个数对应的指针放在最右边
        int k = n-1;
        int target = -nums[i];
        // 枚举b
        for (int j = i+1; j < n; j++)
        {
            // 也是和第一个数一样，不能重复
            if (j>i+1 && nums[j]==nums[j-1])
            {
                continue;
                
            }
            while (j<k && nums[j]+nums[k]> target)
            {
                k--;
            }
            if (j==k)
            {
                break;
            }
            
            if (nums[j]+nums[k]==target)
            {
                /* code */
                vector<int> t = {nums[j], nums[k], -target};
                ans.push_back(t);
            }  
        }
    }
    
   
    
    return ans;
}

vector<vector<int>> threeNumMy(vector<int>& nums){
    // 三数之和
    int n = nums.size();
    // 先排序
    sort(nums.begin(),nums.end());
    // 循环判断
    vector<vector<int>> ans;
    for (int first = 0; first < n; first++)
    {
        // 固定第一个数 因为不能和之前数重复
        if (first>0&&nums[first]==nums[first-1])
        {
            // 跳过
            continue; // 因为要求  是哪个 值不相等
        }
        int target = -nums[first];
        // 开始寻找第二个数
        int third = n-1;
        for (int second = first+1; second < n; second++)
        {
            // 第二个数一定在第三个数的左边
            // 第二个数也不能重复
            if (second>first+1&&nums[second]==nums[second-1])
            {
                continue;
            }

            while (second<third&&nums[second]+nums[third]>target)
            {
                third--;
            }
            if (second==third)
            {
                break;
            }
            if (nums[second]+nums[third]==target)
            {
                // 找到了
                ans.push_back({nums[first],nums[second],nums[third]});
            }
            
            
            
            

        }
         
        
    }

    return ans;
    
}

int main(){
    vector<int> nums;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int num;
    while (ss>> num)
    {
        /* code */
        nums.push_back(num);
    }
    vector<vector<int>> ans = threeSum(nums);
    // 打印结果
    for (int i = 0; i < ans.size(); i++)
    {
        /* code */
        for (int j = 0; j < ans[i].size(); j++)
        {
            /* code */
            cout << ans[i][j] << " "; 
        }
        cout<< endl;
        
    }
    
    
}