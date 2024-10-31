// 路径总和：找到从根节点到叶子结点 的  总和 ===给定的值的所有路径

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}

};


// 思路  递归+ dfs 回溯
vector<vector<int>> ans;
vector<int> tmp; // 每次的

void findPath(TreeNode* root, int cur){
    if (root==nullptr)
    {
        return;
    }
    // 判断是不是叶子结点
    if (root->left==nullptr && root->right == nullptr && root->val==cur)
    {
        // 符合条件，加入；
        tmp.push_back(root->val);
        ans.push_back(tmp);
        // 加了要立马回溯  弹出
        tmp.pop_back();
        return;
    }

    // 检查左节点和右节点
    // 将当前节点放入tmp中
    tmp.push_back(root->val);
    findPath(root->left, cur-root->val);
    findPath(root->right, cur-root->val);
    // 回溯，弹出
    tmp.pop_back();
    

}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (root==nullptr)
    {
        return ans;
    }
    findPath(root, targetSum);
    return ans;
    
        
}

int main(){

}