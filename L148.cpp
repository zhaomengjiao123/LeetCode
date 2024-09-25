/**
 * @file L148.cpp  排序链表
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/**
 * 时间复杂度是 O(nlogn) 的排序算法包括归并排序、堆排序和快速排序（快速排序的最差时间复杂度是 O(n 
2
 )），其中最适合链表的排序算法是归并排序。
 */
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

//  分治算法 排序  先从中间将链表分割（快慢指针）
// 然后各自排序   最后合并（合并有序链表）
// 递归结束的标志就是链表为空  或者当前链表只有一个节点   就不需要排序了
//递归排序

ListNode* sortList(ListNode* head) {
    return sortList(head,nullptr);

}


ListNode* sortList(ListNode* head, ListNode* tail) {
    // 递归结束的条件  链表为空
    if(head==nullptr){
        return head;
    }
    // 链表只有一个节点  如果只有一个节点  那么头和尾必然是相同的
    if (head->next==tail)
    {
        /* code */
        head->next=nullptr;
        return head;
    }
    // 快慢指针  找到链表的中间位置
    ListNode* slow = head;
    ListNode* fast=head;
    // fast需要一直走到当前链表的最后
    while (fast!=tail)
    {
        /* code */
        slow=slow->next;
        fast=fast->next;
        // 如果不是到尾部了   fast始终多走一步
        if (fast!=tail)
        {
            /* code */
            fast=fast->next;
        }
    }
    // 快慢指针相遇  即是 中点
    ListNode* mid = slow;
    return merge(sortList(head, mid), sortList(mid, tail));

}

// 合并有序 链表
ListNode* merge(ListNode* head1, ListNode* head2){
    // 创建新的头结点
    ListNode* newHead = new ListNode(0);
    ListNode* h1=head1;
    ListNode* h2=head2;

    ListNode* curr = newHead;
    while (h1!=nullptr && h2!=nullptr)
    {
        /* code */
        // 比较大小
        if (h1->val<=h2->val)
        {
            /* code */
            curr->next=h1;
            h1=h1->next;
        }else{
            curr->next=h2;
            h2=h2->next;
        }
        curr=curr->next;
        
    }
    if (h1)
    {
        curr->next=h1;
    }
    if (h2)
    {
        /* code */
        curr->next=h2;
    }
    return newHead->next; 
}