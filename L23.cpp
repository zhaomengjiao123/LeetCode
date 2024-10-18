// 给你一个链表数组，每个链表都已经按升序排列。

// 将所有链表合并到一个升序链表中，返回合并后的链表


// 分治 归并

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 两两链表升序合并
ListNode* mergeTwoLists(ListNode* a, ListNode* b){
    // 如果 其中有一个链表为空，直接返回另一个
    if (!a||!b){
        return a? a:b;
    }
    ListNode head, *tail = &head, *at= a, *bt=b;
    // 只要两个来表还有 就继续
    while (at&&bt)
    {
        if (at->val<bt->val)
        {
            // 接入a的这个节点
            tail->next=at;
            at=at->next;
        }else{
            // 接入b的这个节点
            tail->next=bt;
            bt=bt->next;
        }
        tail=tail->next;
        
    }
    // 剩下的看看还有没有每处理完的  直接接入
    tail->next=at?at:bt;
    return head.next;   
}

// 拆分成两部分
ListNode* merge(vector<ListNode*>& lists, int l, int r){
    if (l==r) // 说明正好已经全部二分完了
    {
        return lists[l];
    }
    if (l>r)
    {
        return nullptr;
    }
    int mid = (l+r)/2;
    return mergeTwoLists(merge(lists, l, mid),merge(lists, mid+1, r));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists,0, lists.size()-1);

}