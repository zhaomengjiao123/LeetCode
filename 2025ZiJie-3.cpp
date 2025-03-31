/**
 * @file 2025ZiJie-3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 /**
  * hy最近学习了树的直径。其中，定义了简单路径是不经过重复边或重复点的路径，而树的直径是树上两点之间的最长简单路径。
现在hy突发奇想，想到了一个很有趣的问题。
如果一棵树的直径只有一条，至少需要添加几个结点，才能保证这棵树的直径不唯—?
注意:增加结点时，会先指定原树上的一个结点，然后和这个新的结点连接一条长度为1的边，所以新加入结点后，依旧是一棵树。在本题中，您不需要指定原树上的结点，只需要输出最少需要添加的结点数量。
输入描述
第一行输入—个整数T(1≤T≤100)表示测试数据的数目。
接下来每组数据的第一行输入一个整数
n (1Sn<2x 105)表示树的结点数。
此后n―1行，第i行输入两个整数
vi , ui (1 ≤ui,vi≤n)表示第i条边连接了ui , vi两个结点。保证构成一棵树。(本题保证所有n的和不会超过2e5)

  * 
  */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> // for std::pair
#include <limits> // for std::numeric_limits
using namespace std;

vector<vector<int>> adj; // 邻接表表示图
vector<bool> visited;
vector<int> parent;
vector<int> depth; // 记录每个节点的深度

void bfs(int beign){
    queue<int> q;
    q.push(beign); // 将起始节点加入队列
    visited[beign] = true; // 标记起始节点为已访问
    depth[beign] = 0; // 起始节点的深度为0
    while (!q.empty())
    {
        int cur = q.front(); // 获取队头节点
        q.pop(); // 弹出队头节点
        for (int i = 0; i < adj[cur].size(); ++i) // 遍历当前节点的邻接节点
        {
            int next = adj[cur][i]; // 获取邻接节点
            if (!visited[next]) // 如果邻接节点未被访问
            {
                visited[next] = true; // 标记为已访问
                parent[next] = cur; // 设置父节点
                depth[next] = depth[cur] + 1; // 更新深度
                q.push(next); // 将邻接节点加入队列
            }
        }
    }
   
                                       

}

int main(){
    int t;
    cin >> t; 
    while (t--)
    {
        int n;
        cin >> n; // 输入节点数
        adj.assign(n+1, vector<int>()); // 初始化邻接表
        for(int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v; // 输入边的两个端点
            adj[u].push_back(v); // 将边的一个端点加入邻接表
            adj[v].push_back(u); // 将边的另一个端点加入邻接表

        }
        if(n==1){
            cout << 0 << endl; // 如果只有一个节点，输出0
            continue;
        }
        visited.assign(n+1, false); // 初始化访问标记
        parent.assign(n+1, -1); // 初始化父节点
        depth.assign(n+1, 0); // 初始化深度
        bfs(1); // 从节点1开始广度优先搜索
        int u = 1;
        for(int i=2;i<=n;i++){
            if(depth[i]>depth[u]){ // 找到深度最大的节点
                u = i;
            }
        }
    }
    

}