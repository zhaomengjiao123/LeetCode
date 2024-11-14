// 二叉树中的最大路径和

#include<iostream>
#include<vector>
#include<algorithm>
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
int getMaxPath(TreeNode* root){
    if (root==nullptr)
    {
        return 0;
    }
    // 如果经过这个根节点  必须大于0
    int left = max(getMaxPath(root->left),0);
    int right = max(getMaxPath(root->right),0);
    // 这个节点可以提供的最大的路径和
    int tmp = root->val+left+right;
    // 三条选择：不经过根节点，经过根节点，经过根节点且经过他的子节点
    ans = max(ans, tmp);
    // 这里的返回就说明经过这个根节点或者以及他的子节点了
    return root->val+max(left,right);

    
}

int maxPathSum(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }
    ans = INT_MIN;
    int num = getMaxPath(root);
    return ans;
    

}