// 二叉树的锯齿形层序遍历

// 先从左网游，然后从右往左


// 思路 层次遍历+一个标志

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    vector<vector<int>> ans;
    if (root==nullptr)
    {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);
    // 标志位，当前层是否需要翻转？ 开始时不需要
    int flag = false;
    while (!q.empty())
    {
        // 当前层的  节点的数量
        int curNum = q.size();
        ans.push_back(vector<int> ());
        for (int i = 0; i < curNum; i++)
        {
            TreeNode* cur = q.front();
            q.pop();
            ans.back().push_back(cur->val);
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
        // 查看当前的这一层是否需要翻转？
        if (flag)
        {
            reverse(ans.back().begin(),ans.back().end());
        }
        flag = !flag;
        
        

    }
    return ans;
    
    
        
}