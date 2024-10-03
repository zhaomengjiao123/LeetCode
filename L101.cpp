/**
 * @file L101.cpp 对称二叉树
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 检查给的树  是否是轴对称？左子树=  另一个的右子树 根节点=根节点
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

bool isDuichen(TreeNode* left, TreeNode* right){
    if (left==nullptr&&right!=nullptr)
    {
        return false;
    }
    if (left!=nullptr && right == nullptr)
    {
        /* code */
        return false;
    }
    if(left==nullptr&&right==nullptr){
        return true;
    }
    if (left->val!=right->val)
    {
        return false;
    }
    // 检查左右子树的子树
    bool l = isDuichen(left->left, right->right);
    bool r = isDuichen(left->right, right->left);
    if (l&&r)
    {
        return true;
    }
    
    return false;  
}
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr)
    {
        return true;
    }
    // 检查左子树是否对称
    bool ans = isDuichen(root->left, root->right);
    return ans;

    }