/**
 * @file L226.cpp 翻转二叉树
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 翻转二叉树
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


// 递归？ 所有 的左子树和右子树交换  根节点不变
TreeNode* invertTree(TreeNode* root) {
    if (root==nullptr)
    {
        return nullptr;
    }
    // 暂时存储左子树
    TreeNode* left = invertTree(root->left);
    // 得到翻转后的左右子树
    TreeNode* right = invertTree(root->right);

    root->left = right;
    root->right = left;
    return root;
    

}