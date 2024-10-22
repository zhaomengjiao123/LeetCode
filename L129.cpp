
// 根节点到叶节点的数字和

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



// dfs ？
int getNum(TreeNode* root,int pre){
    if (root==nullptr)
    {
        // nums.push_back(tmp);

        return 0;
    }
    int sum =pre*10 + root->val;

    if (root->left==nullptr && root->right==nullptr)//叶子结点
    {
        return sum;
    }else{
        // 继续遍历左节点和右节点
        return getNum(root->left,sum)+getNum(root->right,sum);
    }

    
    

}

int sumNumbers(TreeNode* root) {
    if (root==nullptr)
    {
        return 0;
    }
    return getNum(root,0);

   
}