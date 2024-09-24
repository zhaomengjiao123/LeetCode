/**
 * @file L141.cpp 环形链表
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 判断链表中是否有环
// 使用哈希表存储？ 如果已经有了那就是有环 Yep!
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> visited;
    ListNode* curr = head;
    while (curr)
    {
        if (visited.count(curr))
        {
            /* code */
            return true;
        }
        visited.insert(curr);
        curr = curr->next;
        
    }
    return false;
    
        
}
