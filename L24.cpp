/**
 * @file L24.cpp   两两交换链表中的节点
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<algorithm>
using namespace std;

// 返回交换后的头结点
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    // 递归  交换链表中的节点   看做2个节点 2个节点组成的小链表
    // 递归结束条件  就是只剩下一个节点  或者 没有节点了
    if (head == nullptr || head->next == nullptr)
    {
        /* code */
        return head;
    }
    // 初始化新的  头结点
    ListNode* newHead = head->next;
    // head的 下一个节点就是 下一对链表的头结点
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}
