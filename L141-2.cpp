// 判断单链表中是否有环
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr){};
    ListNode(int x, ListNode* n):val(x), next(n){};
};

 bool hasCycle(ListNode *head){
    // 思路使用 快慢指针，如果快指针已经先一步变为空或者下一步指向空，说明链表已经结束了，么有换
    // 如果快慢指针相遇说明有环
    // 先判断特殊情况  
    if(head==nullptr || head->next ==nullptr){
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (slow!=fast)
    {
        // 先判断是不是没有环
        if(fast==nullptr || fast->next ==nullptr){
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    
 }


 // 测试
 int main(){
    ListNode* head = new ListNode(3);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    ListNode* r = cur;
    cur->next = new ListNode(0);
    cur = cur->next;
    cur->next = new ListNode(-4);
    cur = cur->next;
    cur->next = r;
    bool ans = hasCycle(head);
    cout << ans <<endl;

 }

