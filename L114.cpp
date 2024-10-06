/**
 * @file L114.cpp 二叉树展开为链表
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/**
 *  展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同
* 二叉树先序遍历：访问根节点、访问左子树，访问右子树
* 先中后序 代表的是根节点的访问位置
 */
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
TreeNode* preNode;

void flatten(TreeNode* root) {
    // 反前序遍历
    if (root==nullptr)
    {
        /* code */
        return;
    }
    flatten(root->right);
    flatten(root->left);
    root->left=nullptr;
    root->right=preNode;
    preNode=root;

    


}