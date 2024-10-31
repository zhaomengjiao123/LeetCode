// 奇偶链表
// 给一个单链表 把所有位置是奇数的节点和 偶数的节点 分别组合在一起，然后返回
// 只能用 O1 的额外空间

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* nx):val(x),next(nx){}
};

ListNode* oddEvenList(ListNode* head) {
    // 自己的思路  把偶数位置的节点拆下来  然后嘴周再组回去
    if (head==nullptr||head->next==nullptr||head->next->next==nullptr)
    {
        return head; // 空链表/一个节点/两个节点  都直接返回
    }
    
    // 偶链表的  虚拟头结点

    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    ListNode* odd_cur = dummy;
    bool flag = true;
    while (cur->next)
    {
        odd_cur->next = cur->next;
        cur->next = cur->next->next;
        odd_cur = odd_cur->next;
        if (cur->next)
        {
            cur = cur->next;    
        }   
    }
    // 和原来的链表断开
    odd_cur->next= nullptr;

    cur->next = dummy->next;
    return head;
    
        
}