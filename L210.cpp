// 课程表2 【0,1】1是0的先修课程
// 需要找到为了学完所有课程所安排的学习顺序
// 找一种拓扑排序？

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;

// 构造边
vector<vector<int>> edges;
vector<int> visited;
bool valid = true;
vector<int> ans; // 相当于是一个栈 栈底的元素才是最后的

void dfs(int u){
    // 标记为探索中
    visited[u]=1;
    // 探索它的后继课程
    for(auto v:edges[u]){
        // 如果没学过
        if (visited[v]==0)
        {
            dfs(v);
           
            if (!valid)
            {
                return;
            }
            
        }else if(visited[v]==1){
            //遇到环了
            valid=false;
            return;
        }
        
    }
    // 当前节点已学习
    visited[u]=2;
    // 放入学完的列表
    ans.push_back(u);

}


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // 初始化边 空间
    edges.resize(numCourses);
    visited.resize(numCourses);
    // 传入边 某个先修课程可能是多个课程的先修课程
    for (auto course:prerequisites)
    {
        edges[course[1]].push_back(course[0]);
    }
    // 开始学习
    for (int i = 0; i < numCourses; i++)
    {
        // 如果没学过这个课程
        if (!visited[i])
        {
            // 学习
            dfs(i);
        }
        
    }
    // 还需要判断是不是有环
    if (!valid)
    {
        return {};
    }
    
    reverse(ans.begin(),ans.end());

    return ans;
    
    
        
}

int main(){
    int numC = 4;
    vector<vector<int>> pre = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = findOrder(numC, pre);
    for (auto num:ans)
    {
        cout << num << endl;
    }
    
}