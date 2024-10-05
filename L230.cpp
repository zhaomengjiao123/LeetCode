/**
 * @file L230.cpp 找到二叉搜索树中第k小的元素
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 因为左子树节点<根节点<右子树节点\
// 中序遍历找到第k个数
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

void inOrder(TreeNode* root, vector<int>& nums, int k){
    if (root==nullptr)
    {
        /* code */
        return;
    }
    
    // 减去当前根节点
    inOrder(root->left, nums,k);
    nums.push_back(root->val);
    if (nums.size()==k)
    {
        return;
    }
    inOrder(root->right,nums,k);

}

int kthSmallest(TreeNode* root, int k) {
    if (root==nullptr)
    {
        /* code */
        return;
    }
    
    vector<int> nums;
    inOrder(root,nums,k);
    return nums[k-1];


}