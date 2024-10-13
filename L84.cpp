// 给定N个非负整数
// 柱子 可以勾勒的矩形的最大面积


// 单调栈

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;



int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);

    stack<int> mono_stack;
    for (int i = 0; i < n; i++)
    {
        while (!mono_stack.empty()&&heights[mono_stack.top()]>=heights[i])
        {
            // 栈顶 位置  的数值  要比当前遍历到的数值大 因此要弹出，
            // 更小的数 入栈
            mono_stack.pop();;
        }
        // 压入 左边界
        left[i]=(mono_stack.empty()?-1:mono_stack.top());
        mono_stack.push(i);
        
    }
    // 重新变为空栈
    mono_stack = stack<int>();
    // 找右边界
    for (int i = n-1; i >=0 ; i--)
    {
        while (!mono_stack.empty()&&heights[mono_stack.top()]>=heights[i])
        {
            mono_stack.pop();
        }
        right[i]=(mono_stack.empty()? n : mono_stack.top());
        mono_stack.push(i);
        
    }
    

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // 以当前位置的数值为高 向两边 找到第一个比它矮的  计算面积
        ans = max(ans, (right[i]-left[i]-1)* heights[i]);
    }

    return ans;
    
    



}
