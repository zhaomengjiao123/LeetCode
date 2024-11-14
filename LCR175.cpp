// 计算二叉树的深度

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



int calculateDepth(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }
    return max(calculateDepth(root->left),calculateDepth(root->right))+1;
    
        
}