/**
 * @file L206.cpp  反转链表
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 /**
  * 直接反向，但是要提前存储前一个节点
  * 
  */
ListNode* reverseList(ListNode* head) {
    ListNode* prev=nullptr;
    ListNode* curr = head;
    while (curr)
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // 因为如果返回curr  到最后一个的时候就是空
    



}