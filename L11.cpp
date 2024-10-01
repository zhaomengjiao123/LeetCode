/**
 * @file L11.cpp 盛水最多的容器
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// 暴力 思路 双层遍历   超时TAT
//
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
using namespace std;


// int maxArea(vector<int>& height) {
//     int ans = 0;
//     for (int i = 0; i < height.size()-1; i++)
//     {
//         /* code */
//         for (int j = 1; j < height.size(); j++)
//         {
//             /* code */
//             // 计算底
//             int b = j-i;
//             // 计算高 短板效应
//             int h = min(height[i], height[j]);
//             // cout << b << h <<endl;
//             ans = max(ans, h*b);
//         }
        
//     }
//     return ans;
// }

// 双指针的 思路，2个指针分别指向两侧，那么总是移动较小的哪个指针
// 直到2个指针重合
int maxArea(vector<int>& height) {
    int l=0, r=height.size()-1;
    int ans = 0;

    while (l<r)
    {
        /* code */
        int area = min(height[l], height[r])*(r-l);
        ans = max(ans, area);
        // 总是移动较小的指针
        if (height[l]<=height[r])
        {
            /* code */
            l++;
        }else{
            r--;
        }
        
    }
    
    
    return ans;
}

int main(){
    vector<int> height;
    string s;
    getline(cin, s);

    stringstream ss(s);
    int num;
    while (ss >> num)
    {
        /* code */
        height.push_back(num);
    }

    int ans = maxArea(height);

    cout << ans << endl;
    

}

