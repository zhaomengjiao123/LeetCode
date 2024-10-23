// 二叉树的层平均值

// 数组形式返回每一层节点的平均值

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




vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    if (root==nullptr)
    {
        return ans;
    }
    // 层序遍历  队列
    queue<TreeNode*> q;
    // 放入根节点
    q.push(root);
    while (!q.empty())
    {
        // 获取这一层的节点的数量
        int curNum = q.size();
        int sum = 0;
        for (int i = 0; i < curNum; i++)
        {
            TreeNode* cur = q.front();
            q.pop();
            // 本层节点的和
            sum = sum + cur->val;
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
            
            

        }
        // 计算平均值
        double av = (double)sum / curNum;
        ans.push_back(av); 
        
    }

    return ans;
    

    
    
        
}