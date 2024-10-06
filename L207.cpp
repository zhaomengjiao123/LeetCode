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
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 用哈希表表示  课程的前驱课程，用另一个哈希表示是否访问过？
    unordered_map<int,int> couse;
    unordered_map<int,int> visited;
    // 先存入哈希表
    int n = prerequisites.size();
    if (numCourses==n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        couse[prerequisites[i][0]]=prerequisites[i][1];
        visited[prerequisites[i][0]]=0;
    }
    

    
    
}