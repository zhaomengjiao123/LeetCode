/**
 * @file L98.cpp 验证二叉搜索树
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 判断一个二叉树是否是有效的二叉搜索树
/*
有效 二叉搜索树定义如下：

节点的左
子树
只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
// 递归判断？
#include<iostream>
#include<sstream>
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


// 左子树上所有节点的值< 根节点的值
// 右子树上所有节点的值>根节点的值
bool helper(TreeNode* root, long long lower, long long upper){
    if (root==nullptr)
    {
        return true;
    }
    if (root->val<=lower || root->val>=upper)
    {
        /* code */
        return false;
    }
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    
    


}


bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
    
    

}