// 填充每个节点的下一个右侧节点 指针

// 视觉效果上的右侧节点，而不是右子树


// 每一层相当于一个链表了

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ret;
    if (!root)
    {
        return ret;
    }
    // 队列  挨个入队
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        // 查看当前层的节点个数
        int curLevelSize = q.size();
        // 添加一个空的一维vector
        ret.push_back(vector<int> ());
        // 拿到当前节点
        // 这一层遍历
        for (int i = 0; i < curLevelSize; i++)
        {
            auto node = q.front();
            q.pop();
            // 比如根节点  就是队列为空 其他的节点就是不能是当前层的最后一个
            if (!q.empty()&&i!=curLevelSize-1)
            {
                node->next = q.front();

            }else{
                node->next =nullptr;
            }
            
            // 把当前这个数，加到数组的最后
            // 就是加到刚刚那个空的一维数组中
            ret.back().push_back(node->val);
            // 分别遍历左子树和右子树
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
            
            
        }
        

    }

    return ret;
    
    
}

Node* connect(Node* root) {
    if (root==nullptr)
    {
        return root;
    }
    

    vector<vector<int>> ans = levelOrder(root);
    return root;

        
}