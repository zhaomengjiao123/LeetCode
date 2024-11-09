// 二叉树的最近公共祖先

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* ans;
bool find(TreeNode* root, TreeNode* p,TreeNode* q){
    if (root==nullptr)
    {
        return false;
    }
    // 查看左子树和右子树是不是包含 制定的节点
    bool left = find(root->left, p, q);
    bool right = find(root->right,p,q);
    // 判断当前根节点是不是公共祖先？
    if ((left&&right)||((left||right)&&(root->val==p->val||root->val==q->val)))
    {
        ans = root;
        return true;
    }
    return left||right||root->val==p->val||root->val==q->val;
    
    

}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr)
        {
            return root;
        }
        find(root,p,q);
        return ans;
        
}