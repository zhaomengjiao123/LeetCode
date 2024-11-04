// 除法求值

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
#include<unordered_map>
#include<queue>
using namespace std;

// 并查集？？？
// 变量之间的倍数关系具有传递性
// 传递性的问题需要使用 并查集！！！
// 在同一个集合中的变量可以通过某种方式计算出他们的比值
// 如果两个变量不在同一个集合中，那么无法计算，返回-1
// a/b 有向加权边 a->b  parent[a]=b 权重是 a/b


vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 建图？
        unordered_map<string, unordered_map<string, double>> graph;
        int n = equations.size();
        // 先把目前给出的 除法及其值 存入  图中
        for (int i = 0; i < n; i++)
        {
            string u = equations[i][0]; // 除数
            string v = equations[i][1]; // 被除数
            double weight = values[i]; // 除法的结果 相当于这条边的权重
            graph[u][v]=weight;
            graph[v][u]=1.0/weight;

        }

        int m = queries.size();
        vector<double> res(m,-1.0); // 把ques 的答案都先初始化为-1.0
        for (int i = 0; i < m; i++)
        {
            string start = queries[i][0];
            string target = queries[i][1];
            // 如果这两个 除数 或者被除数 有一个不在图中，那就是无解的
            if (!graph.count(start)||!graph.count(target))
            {
                continue;
            }
            // 判断除数和被除数相等的情况
            if (start==target)
            {
                res[i]=1.0;
                continue;;
            }
            // 队列？
            queue<pair<string, double>> q;
            // 查询是否被访问过
            unordered_map<string, bool> visited;
            // 先放入 除数
            q.push({start,1.0});
            // 标记为已访问
            visited[start]=true;
            while (!q.empty())
            {
                // 取出当前的除数
                string curr = q.front().first;
                // 结果
                double currVal = q.front().second;
                // 弹出
                q.pop();
                // 如果当前值==目标寻找的被除数
                if (curr==target)
                {
                    res[i]=currVal;
                    break;
                }
                // 否则的话，递归查询图中这个节点的所有被除数
                for (auto neighbor:graph[curr])
                {
                    string next = neighbor.first; // 这个数的除数 使我们的curr的一个被除数
                    double nextVal = neighbor.second; // 我们的curr / next = nextVal
                    // 如果这个节点没有被访问股票
                    if (!visited[next])
                    {
                        // 就访问它
                        visited[next]=true;
                        // 入队
                        q.push({next, curr*nextVal});
                    }
                    

                }
                
                
            }
            

            
            

        }

        return res;
        

        

}