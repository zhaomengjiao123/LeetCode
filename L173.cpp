// 二叉搜索树迭代器

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
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



class BSTIterator {
private:
    vector<int> arr;
    int index;

    void inorder(TreeNode* root, vector<int>& res){
        if (root==nullptr)
        {
            return;
        }
        // 中序遍历 左节点  根节点 右节点
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }

    // 中序遍历 存储数组中
    vector<int> interTraval(TreeNode* root){
        vector<int> res;
        inorder(root, res);
        return res;

    }

public:
    BSTIterator(TreeNode* root) {
        index = 0;
        arr = interTraval(root);
        
    }
    
    int next() {
        return arr[index++];
        
    }
    
    bool hasNext() {
        return index < arr.size();
        
    }
};