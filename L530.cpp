// 二叉搜索树的最小绝对差
// 返回树中 任意两个不同节点之间的最小差值

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

// 全遍历一遍？因为是二叉搜索树  所以最小的差值一定是在相邻的节点之间 父节点和子节点
int ans = INT_MAX;
int pre_val; // 记住了  如果递归中需要改变它本身的值，要用&传递参数
void dfs(TreeNode* root){
    if (root==nullptr)
    {
        return;
    }
    // 检查当前节点与上一个父节点的差值  中序遍历
    dfs(root->left);
    if (pre_val==-1)
    {
        pre_val = root->val;
    }else{
    ans = min(ans, abs(pre_val-root->val));
    pre_val = root->val;
    }
    

    // 分别检查左右子树 
    dfs(root->right);


    
}
int getMinimumDifference(TreeNode* root) {
    if (root==nullptr)
    {
        return ans;
    }
    // 中序遍历
    pre_val = -1;
    dfs(root);
    return ans;
    

        
}