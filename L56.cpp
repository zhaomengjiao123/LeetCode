/**
 * @file L56.cpp 合并给的区间，合并后仍然覆盖原有的区间
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

// 数组普通遍历，本区间的结束值>下一区间的开始值
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    // 题目规定了非空数组
    vector<vector<int>> ans;
    // 无序数组，需要先给数组排序
    sort(intervals.begin(),intervals.end());
    // 记录开始值 和 结束值
    int start = intervals[0][0];
    int end = intervals[0][1];
    // 判断特殊情况，n==1的时候
    if (n==1)
    {
       return intervals;
    }
    
    for (int i = 1; i < n; i++)
    {
        if (end<intervals[i][0])
        {
            // 和 下一区间不重合 直接放入
            ans.push_back({start,end});
            // 重新初始化 开始和结束
            start = intervals[i][0];
            end = intervals[i][1];
              if (i==n-1)
        {
            // 如果是最后一个 直接放入
            ans.push_back({start, end});
        }
        }else if (end>=intervals[i][0])
        {
            // 更新结束值  大的那一个
            end = max(end, intervals[i][1]);
            if (i==n-1)
        {
            // 如果是最后一个 直接放入
            ans.push_back({start, end});
        }
        }

    }
    return ans;
    

}


int main(){
    vector<vector<int>> nums;
    int n = 2;
    int i=0;
    while (i<n)
    {
        vector<int> inter;
        for (int i = 0; i < 2; i++)
        {
            int num;
            cin >> num;
            inter.push_back(num);
        }
        nums.push_back(inter);
        i++;    
    }

    vector<vector<int>> ans = merge(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
        
    }
    
    
}