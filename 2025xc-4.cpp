#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

// 思路：只有当路径上所有节点的权值为偶数时，gcd的值才为偶数


int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // 标记权值为偶数的节点
    vector<bool> even(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        even[i] = (a[i] % 2 == 0);
    }
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        if (even[u] && even[v]) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    vector<bool> visited(n + 1, false);
    long long result = 0;
    
    // 遍历  如果是偶数节点并且未被访问过  就访问
    for (int i = 1; i <= n; ++i) {
        if (even[i] && !visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int cnt = 0;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                cnt++;
                
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            // 为什么计算公式是这个？
            // 因为是假设每个连通块有cnt个节点，那每个节点的路径就是cnt
            // + 任意两个不同节点之间的唯一简单路径
            result += (long long)cnt * (cnt + 1) / 2;
        }
    }
    
    cout << result << endl;
}