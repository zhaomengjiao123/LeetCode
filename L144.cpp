/**
 * @file L144.cpp 二叉树的前序遍历
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> ans;

vector<int> preorderTraversal(TreeNode* root) {
    if (root==nullptr)
    {
        /* code */
        return ans;
    }
    ans.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return ans;
}