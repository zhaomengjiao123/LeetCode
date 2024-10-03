/**
 * @file L169.cpp 多数元素  出现次数> n/2的元素  向下取整
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;
// 数组非空  并且总是存在多数元素  说明只存在一个多数元素，因为其他元素出现的总次数肯定是<n/2
// 暴力：哈希表存储出现的次数 通过了
// 空间O(1)
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int target = floor(n/2);
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }
    for (auto it = hash.begin(); it != hash.end(); it++)
    {
        if (it->second>target)
        {
            return it->first;
        }
        
    }
    return 0;
}

int main(){
    vector<int> nums;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int num;
    while (ss>>num)
    {
        nums.push_back(num);
        
    }

    cout << majorityElement(nums)<<endl;
    
}