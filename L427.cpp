// 建立四叉树

// 用四叉树表示一个矩阵
// 每个内部节点有四个子节点


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


Node* dfs(vector<vector<int>>& grid, int r0, int c0, int r1, int c1){
    for (int i = r0; i < r1; i++)
    {
        for (int j = c0; j < c1; j++)
        {
            // 如果出现了不一样的值，就不是叶节点

            if (grid[i][j] != grid[r0][c0])
            {
                // 返回一个新的节点
                return new Node(
                    true,
                    false,
                    dfs(grid,r0, c0,(r0+r1)/2,(c0+c1)/2),
                    dfs(grid, r0,(c0+c1)/2,(r0+r1)/2, c1),
                    dfs(grid,(r0+r1)/2, c0,r1,(c0+c1)/2),
                    dfs(grid, (r0+r1)/2,(c0+c1)/2,r1,c1)
                );


            }
            
        }
        
    }
    // 是叶节点 直接返回
    return new Node(grid[r0][c0],true);
    

}

Node* construct(vector<vector<int>>& grid) {
    // 使用递归的方法构建四叉树  某一部分必须全为0或者1，否则就要再细分
    return dfs(grid, 0, 0, grid.size(), grid[0].size());
        
}