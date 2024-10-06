
/**
 * @brief  从前序和中序遍历构造二叉树
 * zmj
 * 
 */
// 前序：根节点 左子树 右子树
// 中序：左子树 根节点 右子树
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

unordered_map<int,int> index; // 键：节点的值，值：在中序数组中的位置
TreeNode* myBuildTree(const vector<int>& prorder,const vector<int>& inorder,int preorder_left, int preorder_right, int inorder_left, int inorder_right){
    // 在中序遍历的数组中，左子树的值的位置一定是在右子树的值的位置的左侧
    if(preorder_left>preorder_right){
        return nullptr;
    }
    // 前序遍历的第一节点就是根节点的位置
    int preorder_root = preorder_left;
    // 然后再中序遍历数组中定位根节点的位置
    int inorder_root = index[prorder[preorder_root]];
    // 建立根节点
    TreeNode* root = new TreeNode(prorder[preorder_root]);
    // 得到左子树中节点的数目，那就是中序遍历中根节点左侧的数目
    int size_left = inorder_root-inorder_left;
     // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
    root->left = myBuildTree(prorder,inorder,preorder_left+1,preorder_left+size_left,inorder_left, inorder_root-1);
    root->right = myBuildTree(prorder,inorder,preorder_left+size_left+1,preorder_right,inorder_root+1,inorder_right);
    return root;


}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    // 先把中序数组映射到哈希
    for (int i = 0; i < n; i++)
    {
        /* code */
        index[inorder[i]]=i;
    }
    return myBuildTree(preorder,inorder,0,n-1,0,n-1);
    

}