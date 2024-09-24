/**
 * @file L19.cpp 删除链表的倒数第N个节点
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// 删除链表的倒数第N个节点，并返回头结点
// 先遍历一遍链表 得到链表的长度 L  
#include<iostream>
#include<algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *n):val(x), next(n) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 先遍历一遍链表  按到总长度
    int length = 0;
    ListNode*  curr = head;
    while (curr!=nullptr)
    {
        /* code */
        length++;
        curr = curr->next;
    }
    // 重新遍历  找到第 L-N 个节点
    // 先添加虚拟头结点
    ListNode* dmmy = new ListNode(0,head);
    ListNode* now = dmmy;
    for (int i = 1; i < length-n+1; i++)
    {
        /* code */
        now = now->next;
    }
    // 最后一个就是
    now->next = now->next->next;
    ListNode* ans = dmmy->next;
    delete dmmy;
    return ans;
    
    

}