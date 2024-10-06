/**
 * @file L124.cpp 二叉树中的最大路径和
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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
    int tmp = max(max(l,r),l+r);
    ans= max(ans, max(tmp+root->val,root->val));

    // 因为有可能是负数，所以也可能不加左右节点
    return max(max(l,r)+root->val,root->val);
}

int maxPathSum(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }
    ans = INT32_MIN;
    int tmp = maxDepth(root);
    // 查找左右子树的最大深度
    return ans;

    

}