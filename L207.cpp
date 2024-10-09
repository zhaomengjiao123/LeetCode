/**
 * @file L207.cpp 课程表
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
*/
// 修某门课程 必须先修完前置课程
// 如果存在  路径长度为 target 的非环就是可以的
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
// 某个课程为起点，是否存在长度为X的路径？DFS？
// 需要标记这门课程是不是学过
// 拓扑排序
vector<vector<int>> edges;
vector<int> visited;
bool vaild=true;  // 标志是否有环

void dfs(int u){
    // 对于当前的节点
    // 先标记为正在搜索
    visited[u]=1;
    // 查看其下一个节点
    for (int v: edges[u])
    {
        // 如果这个前驱课程还没有搜索，就索索
        if (visited[v]==0)
        {
            dfs(v);
            if (!vaild)
            {
               return;
            }
            
        }else if (visited[v]==1)
        {
            // 正在搜索u的前置节点，发现了一个正在搜索的节点，说明出现了环
            // 不可能完成任务，直接返回
            vaild = false;
            return;
        }  
    }
    // 标记  搜索完成
    visited[u]=2;
    
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
// 对图进行一遍深度优先搜索。当每个节点进行回溯的时候，我们把该节点放入栈中。
//最终从栈顶到栈底的序列就是一种拓扑排序 
// 每个节点：未搜索、搜索中（未入栈）、已完成
// 当所搜索的节点周围的节点都是已完成的时候，这个节点就可以入栈了
    edges.resize(numCourses);
    visited.reserve(numCourses);
    // 先全都放到  数组中

    for (const auto& info:prerequisites)
    {
        // 把前驱课程放在前面
        // vector [i]
        // 相当于某个课程的全部前驱课程
        edges[info[1]].push_back(info[0]);
    }
    for (int i = 0; i < numCourses && vaild; i++)
    {
        // 未完成的节点
        // 如果当前节点未搜索，就索索
        if (!visited[i])
        {
            dfs(i);
        }
        
    }
    return vaild;
    
    

    
    
}