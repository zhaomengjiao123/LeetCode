/**
 * @file L2.cpp 链表 两数相加
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 两个非空链表 存储两个整数，每个位 一个节点  相加，并返回相同表示形式的链表
// 两个指针  


#include<iostream>
#include<algorithm>
using namespace std;

// 定义节点
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 初始化一个新的链表 头结点
    ListNode* prehead = new ListNode(-1);
    ListNode* curr = prehead;
    int tmp = 0; // 表示进位的数值
    while (l1 != nullptr && l2!=nullptr)
    {
       // 计算当前节点的值
       int val = l1->val+l2->val+tmp;
       // 更新进位
       tmp = 0;
       // 计算新的进位
       tmp = val / 10;
       int num = val % 10;
       ListNode* now = new ListNode(num);
       curr->next = now;
       curr = curr->next;
       l1 = l1->next;
       l2 = l2->next;
    }
    if (l1!=nullptr)
    {
        while (l1!=nullptr)
        {
             /* code */
        // 计算当前节点的值
       int val = l1->val+tmp;
       // 更新进位
       tmp = 0;
       // 计算新的进位
       tmp = val / 10;
       int num = val % 10;
       ListNode* now = new ListNode(num);
       curr->next = now;
       curr = curr->next;
       l1 = l1->next;

        } 
    }
    if (l2!=nullptr)
    {
        while (l2!=nullptr)
        {
           
        
        // 计算当前节点的值
       int val = l2->val+tmp;
       // 更新进位
       tmp = 0;
       // 计算新的进位
       tmp = val / 10;
       int num = val % 10;
       ListNode* now = new ListNode(num);
       curr->next = now;
       curr = curr->next;
       l2 = l2->next;
        /* code */
        }

    }
    // 还存在一种情况就是 最后 ！还剩下进位没有处理  因为最后的节点数值比较大
    if (tmp!=0)
    {
       ListNode* now = new ListNode(tmp);
       curr->next = now;
       curr = curr->next;
    }
    
    return prehead->next;
    
    


}