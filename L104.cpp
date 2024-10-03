/**
 * @file L104.cpp 二叉树的最大深度
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// 递归
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int maxDepth(TreeNode* root) {
    if (root == nullptr)
    {
        return 0 ;
    }
    return max(maxDepth(root->left), maxDepth(root->right))+1;
    

}

