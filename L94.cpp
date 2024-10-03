/**
 * @file L94.cpp 二叉树的中序遍历
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
//按照访问左子树——根节点——右子树的方式遍历这棵树，先访问根节点，然后访问左子树，最后访问右子树
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), 
    left(left), right(right){}
};

void inorder(TreeNode* root, vector<int>& res){
    if (!root)
    {
        return;
    }
    // 遍历左子树
    inorder(root->left, res);
    // 遍历根节点
    res.push_back(root->val);
    // 遍历右子树
    inorder(root->right, res);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
   
    
    

}