#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 链表翻转
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int x):val(x), next(nullptr){};
    ListNode(int x, ListNode* n):val(x), next(n){};
};

ListNode* reverse(ListNode* head){
    // 思路  使用三个指针：前  现在 下一个  不停的交换反转指针的方向
    // 判断空链表 以及  下一个节点为空的情况
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* prev = nullptr; // 开始时这个要置为空指针
    ListNode* cur = head;
    while (cur!=nullptr)
    {
        ListNode* n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
    }
    return prev; // 为什么返回的是prev而不是 cur?因为这个时候的cur可能是会为null的，但是prev不会
    
}

int main(){
    ListNode* head  = new ListNode(1);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(5);
   
    // 翻转
    ListNode* newHead = reverse(head);
    while(newHead!=nullptr){
        cout<<newHead->val<<endl;
        newHead = newHead->next;
    }
}