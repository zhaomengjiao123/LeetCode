/**
 * @file L376.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/**
 * 最长摆动子序列的长度？
 */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 贪心
// 直接从序列的开始计算，因为子序列可以不连续，所以中间遇到的不波动的 我们直接跳过就行了？
int wiggleMaxLength(vector<int>& nums) {
    int len = nums.size();
    if(len<2){
        return len;
    }
    // 因为是标志位  所以一开始不能赋任何值
    int direction;
    int res = 0;
    for(int i=1;i<len;i++){
        // 如果无变化
        if(nums[i]==nums[i-1]){
            continue;
        }
        // 有变化 ，升高了
        if(nums[i]>nums[i-1]){
            // 如果上一次也是升高，不计算
            if(direction==1){
                continue;
            }
            // 否则的话，记录升高
            direction=1;
            res++;
        }else{
            // 降低了
            // 如果上一次也是降低，就不统计
            if(direction==0){
                continue;
            }
            direction=0;
            res++;
        }

    }
    // 目前统计的事变化次数，但是要求返回结果次数 所以+1
    return res+1;

    
}

