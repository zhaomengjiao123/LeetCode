// 分隔链表
// 将所有的小于x的节点都放在大于等于x的节点之前
// 排序？
// 分区的相对位置不能改变




#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *n):val(x), next(n) {}
};


// 使用2个子链表
// 一个顺序存储比x小的节点另一个顺序存储比x大的节点


ListNode* partition(ListNode* head, int x) {
    if (head==nullptr||head->next==nullptr)
    {
        return head;
    }

    // 构造两个新的子链
    ListNode* small_head = new ListNode(-1);
    ListNode* big_head = new ListNode(-1);
    // 分别记录当前的节点
    ListNode* cur_small = small_head;
    ListNode* cur_big = big_head;

    ListNode* cur = head;
    while (cur)
    {
        if (cur->val<x)
        {
            // 放入小的子链中
            cur_small->next = cur;
            cur_small = cur_small->next;
        }else{
            cur_big->next=cur;
            cur_big=cur_big->next;
        }
        cur=cur->next;
    }
    // 连接大小子链
    cur_small->next=big_head->next;
    cur_big->next=nullptr;
    return small_head->next;
    
    // 对啦！！！^-^
        
}