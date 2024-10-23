// 求完全二叉树的节点个数

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
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

int getNum(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    return getNum(root->left)+getNum(root->right)+1;
    
}




int countNodes(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }

    
    int ans = getNum(root);
    return ans;
    

        
}