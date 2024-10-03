/**
 * @file L543.cpp 二叉树的直径
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/**
 * 给你一棵二叉树的根节点，返回该树的 直径 。
二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。
这条路径可能经过也可能不经过根节点 root 。
*/
// 左子树的最深+右子树的最深？

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

int ans;

int maxDepth(TreeNode* root){
    if (root==nullptr){
        return 0;
    }
    //计算左节点的深度
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    // 更新答案
    ans= max(ans, l+r+1);

    
    return max(l,r)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }
    ans = 1;
    // 查找左右子树的最大深度
    return ans-1;

    

}