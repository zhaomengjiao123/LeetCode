// 蛇梯棋
// n*n 的矩阵

// 不能连续走过蛇或者梯子
// 每个蛇或者梯子只能走一次

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<sstream>
using namespace std;

// 建图
// 如果从x出发 x+i的位置没有蛇或者梯子, x->x+i 一个边
// 如果x+i有蛇或者梯子  x->蛇或者梯子的目的地
// BFS
//将 每个节点以及对应的可移动次数  放到队列
// 每次取出队首，遍历它的出边，如果没有被访问过  就+1访问
// 另外如果是偶数行  方向是 左向右  如果是奇数行 方向是 右向左


pair<int, int> id2rc(int id, int n){
    // 为什么id需要先-1？（因为我们是从1开始出发的，下标-1）
    int r = (id-1)/n; //　行
    int c = (id-1)%n; // 列
    // 计算方向 偶数行 左-》有  奇数行  右-》左
    if (r%2==1)
    {
        // 只要 奇数行需要改变方向
        c = n-1-c;
    }
    return {n-1-r, c};
    
}


int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> vis(n*n+1);
    queue<pair<int, int>> q;
    // 第一个节点的  移动步数 是0
    q.emplace(1,0);
    while (!q.empty())
    {
        // 取出当前节点 遍历它的出边
        auto p = q.front();
        q.pop();
        // 因为是模拟的掷骰子  所以下一步只有6个可能的目的地
        for (int i = 1; i <= 6; i++)
        {
            int nex = p.first+i; // 给坐标移动
            // 超出边界就返回
            if (nex>n*n)
            {
                break;
            }
            // 计算下一步的行 和 列
            auto rc = id2rc(nex, n);
            // 查看下一步是否存在蛇或者梯子
            if (board[rc.first][rc.second]>0)
            {
                // 走蛇或者梯子
                nex = board[rc.first][rc.second];
            }
            // 如果已经达到终点
            if (nex==n*n)
            {
                return p.second+1; // 后面那个数代表走了多少步
            }
            // 如果没被访问过  标记
            if (!vis[nex])
            {
                vis[nex]=true;
                q.emplace(nex, p.second+1); // 因为我们是从P点 走到这个位置的
            }
            
            
            

            
        }
        
    }

    return -1;
    
        
}

int main(){
    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };
    int ans = snakesAndLadders(board);
    cout << ans << endl;
    
}