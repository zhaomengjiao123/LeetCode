/**
 * @file L160.cpp 相交链表
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/**
 * 给你两个单链表的头节点 headA 和 headB ，
 * 请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

// 先遍历一个链表并存储？，然后遍历另一个链表，查看每个节点？ 是的  用哈希表存储

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 创建哈希表  存储第一个链表的值
    // 指针  允许存储不重复的指针
    unordered_set<ListNode *> visited;
    ListNode *tmp = headA;
    //将这个链表全部放到哈希表中
    while (tmp != nullptr)
    {
        /* code */
        visited.insert(tmp);
        tmp = tmp -> next;
    }
    //  检查第二个链表
    tmp = headB;
    while (tmp!=nullptr)
    {
        /* code */
        if (visited.count(tmp))
        {
            /* code */
            return tmp;
        }
        tmp = tmp->next;
        
    }
    return nullptr;
}