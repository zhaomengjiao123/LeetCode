#include<iostream>
#include<algorithm>
#include<vector>
#include <iostream>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

// N个同学排成一列，每个同学只能右侧看到比他矮的同学，每个同学能看到的同学的总数 代表队列的整齐度
//给定n个整数 n<=100000 计算队列的整齐度 数组中的数非常大
//从左往右找 每个元素 右侧有多少比他小的


// 单调栈

long long calculateNeatness(vector<int>& heights) {
    int n = heights.size();
    stack<pair<int, int>> stk; // 存储身高和索引
    long long neatness = 0;

    for (int i = n - 1; i >= 0; --i) {
        int currentHeight = heights[i];
        int visible = 0;

        // 弹出所有比当前身高矮的同学
        while (!stk.empty() && stk.top().first < currentHeight) {
            // cout<<"pop : "<<stk.top().first<<" "<<stk.top().second<<endl;
            stk.pop();
        }

        // 如果栈不为空，说明右边有比当前身高高的同学
        if (!stk.empty()) {
            visible = stk.top().second - i;
        } else {
            if(i==n-1){
                visible = 0;
            }else{
                visible = n - i - 1; // 如果栈为空，说明右边所有同学都比当前矮
            }
            
        }

        // 将当前同学的身高和索引压入栈
        stk.push({currentHeight, i});
        // cout<<currentHeight<<" "<<i<<" "<<visible<<endl;
        neatness += visible;
    }

    return neatness;
}




int main(){
    int n;
    cin>>n;
    vector<int> mate;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        mate.push_back(a);
    }
    long long res = calculateNeatness(mate);
    cout<<res<<endl;
}