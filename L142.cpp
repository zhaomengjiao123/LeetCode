/**
 * @file L142.cpp  环形链表2  
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 返回入环的第一个节点 
// 哈希存储其节点以及对应的索引
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> hash;
    ListNode* curr = head;
    while (curr)
    {
        if (hash.count(curr))
        {
            // 如果已经存在对应的节点，那么这个节点就是入环的节点
            return curr;
        }
        hash.insert(curr);
        curr=curr->next;
        
    }
    return nullptr;
    
        
}