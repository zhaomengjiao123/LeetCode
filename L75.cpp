/**
 * @file L75.cpp 颜色分类
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/**
 * 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库内置的 sort 函数的情况下解决这个问题。
*/
// 原地排序？ 双指针  因为只有三个元素0 1 2
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    // 左右两个指针
    int r=0, l=n-1;
    // 当两个指针不重合的时候
    for (int i = 0; i <=l; i++)
    {
        // 当找到2的时候就往后放，和l交换
        while (i<=l && nums[i]==2)
        {
            //交换位置
            // 如果本来l的位置就是2
            swap(nums[i],nums[l]);
            l--;
        }
        // 当找到0 的时候，与r交换位置
        if (nums[i]==0)
        {
            
            swap(nums[i], nums[r]);
            r++;
        }
        
        
    }
    
    
        
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
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<< " ";
    }
    
    
}