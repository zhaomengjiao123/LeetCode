// 从中序遍历与后序遍历 序列构造二叉树


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map> 
using namespace std;




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


unordered_map<int, int> index;
int post_id ;


TreeNode* mybuild(vector<int>& inorder,vector<int>& postorder,int in_left,int in_right){
    // 中序遍历的数组中 左子树的节点一定是小于右子树的节点
    if (in_left>in_right)
    {
        return nullptr;
    }
    // 找到根节点  后序遍历的最后一个节点就是根节点
    // 在中序遍历中找到根节点的位置
    int in_root = index[postorder[post_id]];

    // 那么左侧的就是左子树，右侧就是右子树，递归构建
    TreeNode* root = new TreeNode(postorder[post_id]);
    post_id--;

       // 构建右子树
    root->right = mybuild(inorder,postorder,in_root+1,in_right);


    //递归构建左子树
    root->left = mybuild(inorder, postorder,in_left,in_root-1);
 
    return root;

    

}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        post_id = postorder.size()-1;
        // 将中序遍历映射到哈希
        for(int i=0;i<n;i++){
            index[inorder[i]]=i;
        }

        return mybuild(inorder,postorder,0,n-1);
        
}