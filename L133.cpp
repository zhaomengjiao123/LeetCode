// 克隆图
// 给一个无向连通图的 节点的引用，返回 图的深拷贝

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<unordered_set>
#include<unordered_map>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// 哈希表 key是原图的节点 value是克隆图中的节点
unordered_map<Node*, Node*> visited;


// 使用哈希存储是不是已经访问过了？
Node* cloneGraph(Node* node) {
   if (node==nullptr)
   {
    // 如果是 空节点 直接返回
    return node;
   }
   // 如果该节点已经被访问过了，就从哈希表中取出该节点的克隆节点  返回？
   if (visited.find(node)!=visited.end())
   {
    return visited[node];
   }

   // 克隆本节点
   // 但是为了深拷贝 不会克隆它的 邻居的列表
   Node* cloneNode = new Node(node->val);
   // 存到哈希表
   visited[node]=cloneNode;
   // 遍历这个节点的邻居 同时更新 克隆节点的  邻居列表
   for (int i = 0; i < node->neighbors.size(); i++)
   {
     cloneNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
   }

   return cloneNode;
   
   
   
    
        
}