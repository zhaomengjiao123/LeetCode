// 升序链表
// 二叉搜索树的中序遍历就是升序的
// 有序链表 转成平衡的二叉搜索树 左右子树的高度相差不超过1


// 分治的思想

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* l,TreeNode* r):val(x),left(l),right(r){}
};

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* l):val(x),next(l){}
};

// 找到中间节点
ListNode* getMid(ListNode* left, ListNode* right){
    // 快慢指针寻找中间节点
    ListNode* fast = left;
    ListNode* slow = left;
    while (fast!=right&&fast->next!=right)
    {
        fast=fast->next->next;
        slow =slow->next;
    }
    return slow;
    
}

// 建树
TreeNode* builTree(ListNode*  left, ListNode* right){
    if (left==right)
    {
        return nullptr;
    }
    // 找到中间节点  就是 根节点
    ListNode* mid = getMid(left, right);
    // 建立根节点
    TreeNode* root = new TreeNode(mid->val);
    // 循环建立左子树和右子树
    root->left = builTree(left,mid);
    root->right = builTree(mid->next,right);
    return root;
    
}

TreeNode* sortedListToBST(ListNode* head) {
    if (head==nullptr||head->next==nullptr)
    {
        TreeNode* headT = new TreeNode(head->val);
        return headT;
    }
    // 找到中间节点 递归建树
    return builTree(head, nullptr);     
}

int main(){
    ListNode* head = new ListNode(-10);
    vector<int> nums = {-3,0,5,9};
    ListNode* cur = head;
    for (int i = 0; i < nums.size(); i++)
    {
        ListNode* newL = new ListNode(nums[i]);
        cur->next = newL;
        cur = cur->next;
    }
    TreeNode* newT = sortedListToBST(head);

    
   
   

}