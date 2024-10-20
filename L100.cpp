// 相同的树
// 给两个根节点 判断这两个树是否相同？



#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;



 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    // 递归判断
    if (p==nullptr&&q==nullptr)
    {
        return true;
    }
    if ((p==nullptr&&q!=nullptr) ||(p!=nullptr&&q==nullptr))
    {
        return false;
    }

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    return p->val==q->val && left && right;
    
    
        
}