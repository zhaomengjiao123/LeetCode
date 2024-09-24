/**
 * @file L21.cpp  合并两个有序链表
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 将两个升序链表 合并成 一个升序链表并返回
// 先存储后排序 后返回
// 两个指针  一个一个  每个都比较

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* l1 = list1;
    ListNode* l2 = list2;
    ListNode* newList = new ListNode(-1);
    ListNode* curr=newList;
    while (l1!=nullptr && l2!=nullptr)
    {
        if (l1->val<l2->val)
        {
            /* code */
            curr->next=l1;
            l1=l1->next;
        }else {
            /* code */
            curr->next=l2;
            l2=l2->next;
        }
        curr = curr->next; 
    }
    // 直接指向剩下的节点
    if (l1!=nullptr)
    {
       curr->next=l1;
    }
    if (l2!=nullptr)
    {
       curr->next=l2;
    }
    return newList->next;
    
    
        
}