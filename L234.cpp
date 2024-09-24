/**
 * @file L234.cpp  回文链表
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 判断给定的链表是不是回文链表
//哈希存储？前半段开始存储到哈希表中，当遇到哈希表已经存在的时候，就开始判断  完全不行
// 用递归
#include<iostream>
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
ListNode* frontPointer;

bool recursivelyCheck(ListNode* curr){
    // 如果当前节点存在  返回F  不存在 返回T
    if (curr != nullptr)
    {
        /* code */
        if (!recursivelyCheck(curr->next))
        {
            /* code */
            return false;
        }
        if (curr->val != frontPointer->val)
        {
            /* code */
            return false;
        }
        frontPointer = frontPointer->next;
        
        
    }
    return true;
    
}

bool isPalindrome(ListNode* head) {
    frontPointer = head;
    return recursivelyCheck(head);


}