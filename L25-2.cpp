#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){};
    ListNode(int x, ListNode* n):val(x), next(n){};
};



// 函数 翻转给定头结点和尾结点的链表
pair<ListNode*,ListNode*> reverse(ListNode* head, ListNode* tail){
    // 先保存尾结点的后一个节点
    ListNode* prev = tail->next;
    ListNode* cur = head;
    // 循环终止的条件就是循环到尾部节点了
    while (prev != tail)
    {
        ListNode* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return {tail, head};
    

}

// K个一组翻转链表
ListNode* reverseKGroup(ListNode* head, int k){
    // 判断空链表的情况
    if(head==nullptr || head->next ==nullptr){
        return head;
    }
    // 创建一个虚拟头结点   K个一组翻转
    ListNode* dummy = new ListNode(0, head);
    ListNode* cur = dummy;
    ListNode* prev = dummy;
    ListNode* newHead = head;
    // 找到第K个节点的前一个节点
    while (cur!=nullptr)
    {
        // 找K个节点
        for (int i = 0; i < k; i++)
        {
            cur = cur->next;
            // 在找前K个节点的时候，也有可能是找不到
            if (cur==nullptr)
            {
                // 说明不够K格节点  不翻转
                return dummy->next;
            }
            
        }
        // 第K格节点就是尾结点
        ListNode* tail = cur;
        // 头结点就是newHead
        // 找到后一个节点 防止断开
        ListNode* after = tail->next;
        // 将这K格节点与原来的链表断开
        prev->next = nullptr;
        tail->next = nullptr;
        //翻转
        // 新的头结点
        pair<ListNode*, ListNode*> tmp = reverse(newHead, tail);
        prev->next = tmp.first;
        tmp.second->next = after;
        //设置新的头尾节点
        prev = tmp.second;
        newHead = prev->next;
        cur = prev;


        
    }
    return dummy->next;
    

}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(5);


    ListNode* newhead = reverseKGroup(head,3);
    ListNode* now = newhead;
    while (now!=nullptr)
    {
        /* code */
        cout<< now->val<<endl;
        now = now->next;
    }
    



}