/**
 * @file L127.cpp 二叉树中的最大路径和
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


int getAns(TreeNode* root, int sum){
    if (root==nullptr)
    {
        /* code */
        return sum;
    }
    int left = getAns(root->left, sum);
    int right = getAns(root->right,sum);
    int nowMax = max(left, right)
    
}

int maxPathSum(TreeNode* root) {

}