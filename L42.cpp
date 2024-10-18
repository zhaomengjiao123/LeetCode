

// 接雨水

// 单调栈

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;


int trap(vector<int>& height) {
    int ans = 0;
    stack<int> stack;
    int n = height.size();
    // 为什么单调栈可以解决问题？
    // 单调栈是降序的 当height i > top 的时候， 因为 top-1的位置也是 大于top
    // 因此形成了洼地
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty()&&height[i]>height[stack.top()])
        {
            // 计算能够接到的雨水
            int tmp = stack.top();
            stack.pop();
            if (stack.empty())
            {
                break; // 因为这时候就空了的话  说明 这个洼地没有另一边
            }
            int left = stack.top();
            int width = i-left-1;
            // 高度是  比较矮的哪个
            // 为什么要减去这个  只求网上的
            int h = min(height[left],height[i])-height[tmp];
            ans = ans + h*width;
            
        }
        stack.push(i);
        
    }
    return ans;
    

}

int main(){

    string s;
    getline(cin, s);
    vector<int> nums;

    stringstream ss(s);

    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }

    int ans = trap(nums);

    cout << ans << endl;
    

}