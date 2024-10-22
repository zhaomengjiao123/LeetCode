// 查找二叉树有没有才能够根节点到叶子结点的路径上的数值的和等于给定的值


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool findPath(TreeNode* root, int cur){
    // 先判断是不是空节点
    if (root==nullptr)
    {
        return false;
    }
    
    // 判断是否是叶子结点
    if (root->left==nullptr&&root->right==nullptr&&cur==root->val)
    {
        return true;
    }
    
    // 减去当前值 是否合适？
   
    // 左右子树
    bool left = findPath(root->left, cur-root->val);
    bool right = findPath(root->right,cur-root->val);
    return left || right;
    
    
}



bool hasPathSum(TreeNode* root, int targetSum) {
    // 判断特殊请跨国
    if (root==nullptr)
    {
        return false;
    }
    
    return findPath(root, targetSum);
    
        
}
