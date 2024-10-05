/**
 * @file L199.cpp 二叉树的右视图
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 返回从右侧能看到的节点的值  从上到下
// 只能看到根节点-右子树 的右子树
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 存在右子树的时候只能看到右子树，不存在右子树的时候看到左子树
// 有个问题是不知道树的形状，有可能是左子树更长！
// void getRight(TreeNode* root, vector<int>& ans){
//     if (root==nullptr)
//     {
//         return;
//     }
//     ans.push_back(root->val);
//     // 如果存在右子树，只看右子树
//     if (root->right)
//     {
//         /* code */
//         getRight(root->right, ans);
    
//     }else{
//         getRight(root->left,ans);
//     }
    
    

// }

vector<int> rightSideView(TreeNode* root) {
    
    unordered_map<int,int> rightVd;
    int max_depth = -1;

    stack<TreeNode*> nodeStack;
    stack<int> depthStack;
    nodeStack.push(root);
    depthStack.push(0);

    while (!nodeStack.empty())
    {
        /* code */
        TreeNode* node = nodeStack.top();
        nodeStack.pop();
        int depth = depthStack.top();
        depthStack.pop();
        // 获取根节点以及记录的深度
        if (node!=NULL)
        {
            // 维护二叉树的最大深度
            max_depth = max(max_depth,depth);
            //// 如果不存在对应深度的节点我们才插入 ??
            if (rightVd.find(depth)==rightVd.end())
            {
                rightVd[depth]=node->val;
            }

            nodeStack.push(node -> left);
            nodeStack.push(node -> right);
            depthStack.push(depth + 1);
            depthStack.push(depth + 1);

            
        }
        
    }
    vector<int> rightView;
    for (int depth = 0; depth <= max_depth; ++depth) {
            rightView.push_back(rightVd[depth]);
        }

    return rightView;

    
    


}