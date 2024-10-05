/**
 * @file L108.cpp 有序数组  转换为二叉树
 * @author zmj
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 平衡二叉搜索树
// 左节点的值<右节点的值，并且高度平衡因子不超过1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 二叉搜索树的中序遍历是升序数组


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* helper(vector<int>& nums, int left, int right){
    if (left > right)
    {
        return nullptr;
    }
    // 总是选择左边的数字作为根节点
    int mid = (left+right)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums,left,mid-1);
    root->right = helper(nums, mid+1,right);
    return root;
    
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    // 总是选择中间左边的数作为  根节点
    return helper(nums,0,nums.size()-1);

}