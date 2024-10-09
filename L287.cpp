/**
 * @file L287.cpp 寻找重复的数
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 给定一个数组 存在至少一个重复的证书 如果只有一个返回这个数
// 不修改数组 只能用O(1)的额外空间
// 快慢指针
// 建立i->nums[i]的链表
// 因为有重复的数，那么肯定存在环
// 用快慢指针确定是否存在环
//如果相遇了，说明存在环，那么一人走一步，相遇的地方就是环的入口，也就是重复的数

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    // 快慢指针
    int slow=0, fast = 0;
    // 因为这里一开始快慢指针是相等的，因此下面这个至少执行一次的话
    // 就要用 do  while
    do
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
    }while (slow!=fast);
    // 一定存在环
    slow = 0;
    while (slow!=fast)
    {
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
    
    
    

}