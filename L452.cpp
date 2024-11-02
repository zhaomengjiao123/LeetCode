// 用最少数量的箭  引爆气球

// 气球的坐标是xstart  xend  但是不知道气球的y坐标
// 其实就是合并区间  然后最后看看有多少个区间  就需要多少个箭
// 不对！！是找到重合的区间  足厚看有多少个重合的区间

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    if (n==1)
    {
        return 1;
    }
    // 合并区间
    vector<vector<int>> ans;
    // 先给区间排序
    sort(points.begin(),points.end());
    // 记录开始值和结束值
    int start = points[0][0];
    int end = points[0][1];
    cout << "first:"<<start<< " "<<end<<endl;
    for (int i = 1; i < n; i++)
    {
        // 如果有重合部分
        if (end>=points[i][1]||(end<points[i][1]&&end>=points[i][0]))
        {
            // 更新开始节点
            start = max(start, points[i][0]);
            // 更新结束节点
            end = min(end, points[i][1]);
        }else{
            // 将上一个直接放入
            cout << start<<" "<<end<<endl;

            ans.push_back({start,end});
            // 更新开始和结束的值
            start = points[i][0];
            end = points[i][1];

        }
        //如果当前是最后一个区间直接放入
        if (i==n-1)
        {
            cout << start<<" "<<end<<endl;
        ans.push_back({start,end});

        }
        
        
        
    }

    return ans.size();
    
    
        
}

int main(){
    vector<vector<int>> points = {{1,2},{2,3},{3,4},{4,5}};
    int ans = findMinArrowShots(points);
    cout << ans <<endl;
}
