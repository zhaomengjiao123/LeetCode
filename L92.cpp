// 反转链表

// 给  head left right 反转 left - right



#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(): val(NULL), next(nullptr){};
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode* n):val(x), next(n){};
};

// 翻转一个链表
void reverse(ListNode* start){
    ListNode* pre = nullptr;
    ListNode* cur = start;
    while (cur!=nullptr)
    {
        // 记录下一个节点
        ListNode* nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    
    // 如果头尾相同 则不需要翻转
    if (left==right)
    {
        return head;
    }
    // 因为头结点可能会发生变化，因此  使用虚拟的头结点
    ListNode* dummyNode = new ListNode(-1);
    dummyNode->next = head;
    // 找到  left 左边的节点
    ListNode* pre_left = dummyNode;
    for (int i = 0; i < left-1; i++)
    {
        pre_left = pre_left->next;
    }
    // 找到左节点
    ListNode* left_node = pre_left->next;
    // 找到结束的节点  right
    ListNode* end_node = pre_left;
    for (int i = left-1; i < right; i++)
    {
        end_node = end_node->next;
    }
    // 结束节点的后一个节点
    ListNode* after_right = end_node->next;
    // 先把 left左边的节点指向 结束的节点
    // 然后把left节点指向空?  总之两边先断联
    pre_left->next = nullptr;
    end_node->next = nullptr;
    // 翻转链表
    reverse(left_node);
    // 接回原来的链表
    pre_left->next = end_node;
    left_node->next=after_right;

    
    
    
    
   
    return dummyNode->next;    
}
