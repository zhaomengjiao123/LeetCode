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


// 创建链表的结构体

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x):val(x),next(nullptr){};
// };


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


// 二刷  判断链表中是否有环

// 思路 快慢 指针  如果相遇的话 就证明链表中有环
bool hasCycle2(ListNode *head) {
    if (head==nullptr || head->next == nullptr)
    {
        return false;
    }
    ListNode* slow = head ;
    ListNode* fast = head->next;
    while (slow!=fast)
    {
        if (fast==nullptr||fast->next==nullptr)
        {
            // 不存在了 直接  返回  不存在环的话 快指针会直接指向最后一个结点的next
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;

        
    }
    return true;
    
    

}
