/**
 * @file L25.cpp  K个一组翻转链表
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 给定头结点  每 K个一组进行翻转
// 递归？ 如果判断剩下的链表是否满足K个的要求？
#include<iostream>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 翻转一个链表  并返回新的头结点和尾节点
pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail){
    // 为啥要存储 tail的next?
    ListNode* prev=tail->next;
    ListNode* p=head;
    while (prev!=tail)
    {
        ListNode* nex = p->next;
        p->next = prev;
        prev = p;
        p=nex;
    }
    return {tail, head};
    
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* hair = new ListNode(0);
    // 创建一个前置虚拟节点
    hair->next = head;
    ListNode* pre = hair;
    while (head)
    {
        /* code */
        ListNode* tail = pre; // ??  初始化，要瞬移到K个节点的末尾
        // 先查看剩余部分的长度是不是》K
        for (int i = 0; i < k; i++)
        {
            /* code */
            tail=tail->next;
            if (!tail)
            {
                /* code */
                // 若为空  说明不够K个 不改变顺序
                return hair->next;
            }
            
        }
        ListNode* nex = tail->next;
        pair<ListNode*, ListNode*> res = myReverse(head, tail);
        head=res.first;
        tail=res.second;
        // 将得到的子链重新接回去
        pre->next=head;
        tail->next=nex;
        pre = tail;

        head=tail->next;
        


    }
    return hair->next;
    

}


// 给定头结点和尾结点  翻转链表
pair<ListNode*, ListNode*> reverse2(ListNode* head, ListNode* tail){
    ListNode* pre = tail->next;
    ListNode* p = head;
    while (pre!=tail)
    {
        ListNode* nex = p->next;
        p->next = pre;
        pre = p;
        p = nex;
    }
    return {tail, head};
    
}

// K个一组翻转链表 2 刷

ListNode* reverseKGroup2(ListNode* head, int k) {
    if (head==nullptr)
    {
        return head;
    }
    // 虚拟头结点
    ListNode* dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode* pre_left = dummyNode;
    while (head)
    {
        ListNode* tail = pre_left;
        // 查看剩余的长度
        for (int i = 0; i < k; i++)
        {
            tail = tail->next;
            // 如果tail不存在说明不够K个  返回
            if (!tail)
            {
                return dummyNode->next;
            }
            
        }
        // 记录好尾部的下一个节点
        ListNode* after_tail = tail->next;
        // 翻转链表
        pair<ListNode*, ListNode*> res = reverse2(head, tail);
        // 翻转后的头结点和 尾结点
        head = res.first;
        tail = res.second;
        pre_left->next = head;
        tail->next = after_tail;
        //继续下一轮
        pre_left = tail;
        head = tail->next;


        


        
    }
    return dummyNode->next;
    
    

    
}
