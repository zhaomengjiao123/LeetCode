// 重排链表 
/**
 * @brief 给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 思路 找到后半部分链表，用栈存储？然后挨个插入前半段
void reorderList(ListNode* head) {
    // 找到中间节点
    if (head==nullptr||head->next==nullptr||head->next->next==nullptr)
    {
        return;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast!=nullptr&&fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    // slow 就是中间结点  如果是奇数 从下一个开始
    stack<ListNode*> stk;
    ListNode* mid = slow;
    mid = mid->next;
    while (mid)
    {
        stk.push(mid);
        mid = mid->next;
    }
    // slow 断开
    slow->next = nullptr;
    // 前半段遍历插入
    ListNode* cur = head;
    while (!stk.empty())
    {
        ListNode* nex = cur->next;
        cur->next = stk.top();
        stk.pop();
        cur = cur->next;
        cur->next = nex;
        cur = nex;

    }
    return;
    
    
    
    
        
}