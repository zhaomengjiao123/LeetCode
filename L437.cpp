/**
 * @file L437.cpp 求二叉树中路径总和为给定值的  路径的总数目
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<string>
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

// 路径：只能是向下的  节点上的值的总和=target
// 深度优先搜索，对每个节点p，求他的左子树  target-val的数+右子树中target-val的数

int getTargetPath(TreeNode* root, long long target){
    if (root==nullptr)
    {
        /* code */
        return 0;
    }
    // 先判断当前的根节点是不是等于target
    long long ret = 0;
    if (root->val==target)
    {
        /* code */
        ret++;
    }
    ret = ret + getTargetPath(root->left, target-root->val);
    ret = ret + getTargetPath(root->right,target-root->val);
    return ret;
    
    
}

int pathSum(TreeNode* root, long targetSum) {
    if (root==nullptr)
    {
        /* code */
        return 0;
    }
    long long ans = 0;
    ans = ans + getTargetPath(root, targetSum);
    // 因为可以不从根节点开始，因此找做右子树
    ans = ans + pathSum(root->left, targetSum);
    ans = ans + pathSum(root->right, targetSum);
    return ans;
    
    

}