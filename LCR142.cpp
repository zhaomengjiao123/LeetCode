// 训练计划
// 给两个有序链表 形式记录的 训练计划  合并两个链表 升序

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>

using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* l):val(x),next(l){}
};


ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
    // 检查两个链表都不为空
    if (l1==nullptr||l2==nullptr)
    {
        return l1==nullptr?l2:l1;
    }

    // 新的链表  虚拟头结点
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (l1&&l2)
    {
        if (l1->val>=l2->val)
        {
            cur->next = l2;
            l2=l2->next;
        }else{
            cur->next=l1;
            l1=l1->next;
        }
        cur=cur->next;
        
    }
    // 最后检查  谁还剩下了
    if (l1 || l2)
    {
        cur-> next = l1==nullptr?l2:l1;
    }

    return dummy->next;
    
    
    
        
}