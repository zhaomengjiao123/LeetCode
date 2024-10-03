/**
 * @file L102.cpp 二叉树的层序遍历
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 层序遍历  扫描每一层

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ret;
    if (!root)
    {
        return ret;
    }
    // 队列
    queue<TreeNode*> q;
    // 放入根节点
    q.push(root);
    while (!q.empty())
    {
        int currentLevelSize = q.size(); // 当前层的大小
        ret.push_back(vector<int> ());
        // 这一层
        for (int i = 1; i <= currentLevelSize; i++)
        {
            auto node = q.front();
            q.pop();
            // 加到数组的最后
            ret.back().push_back(node->val);
            // 左子树
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