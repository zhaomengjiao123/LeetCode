/**
 * @file L236.cpp 二叉树的最近公共祖先
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 递归判断，符合要求的根节点就是：左子树和右子树分别包含 p q，或者其中一个
// 包含p q，并且root的值是剩下的另一个值
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

TreeNode* ans;

bool getAns(TreeNode* root, TreeNode* p, TreeNode* q){
    if (root==nullptr)
        {
            /* code */
            return false;
        }
    // 查看左子树是否包含p或者q
    bool left = getAns(root->left, p, q);
    bool right =getAns(root->right,p, q);
    //判断
    if ((left&&right)||((root->val==p->val||root->val==q->val)&&(left||right)))
    {
        /* code */
        ans=root;

    }
    return left || right || (root->val==p->val||root->val==q->val);
    


}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        getAns(root,p,q);
        return ans;
        
        
}