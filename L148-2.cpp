#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>


using namespace std;

// 链表排序思路：   二分  然后按有序链表合并，，然后归并

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){};
    ListNode(int x, ListNode* n) : val(x), next(n){};
};

// 合并两个链表 按升序
ListNode* merge(ListNode* head1, ListNode* head2){
    if (head1==nullptr)
    {
        /* code */
        return head2;
    }
    if(head2==nullptr){
        return head1;
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while(head1!=nullptr && head2!=nullptr){
        if(head1->val>=head2->val){
            cur->next = head2;
            head2 =head2->next;
        }else{
            cur->next = head1;
            head1 =head1->next;
        }
        cur = cur->next;
    }
    // 检查有没有剩下的
    if(head1||head2){
        cur->next = head1==nullptr? head2:head1;
    }
    return dummy->next;

    
}


// 将链表二分
// 使用快慢指针找到链表的中间结点  然后二分
ListNode* split(ListNode* head, ListNode* tail){
    // 递归结束的条件就是  只剩下一个节点或者空节点
    if(head==nullptr){
        return head;
    }
    // 如果只剩下2个节点  就返回头节点
    if(head->next==tail){
        //只剩下两个节点 需要分割成两个子链
        head->next = nullptr;
        return head;
    }
    // 使用快慢指针  
    ListNode* slow = head;
    ListNode* fast = head;
    // 这里尤其注意判断条件
    // 因为不是孤立的一个链表了，所以判断是否到末尾的方法就是看是不是和尾结点重合了
    while (fast!=tail)
    {
        slow = slow->next;
        fast = fast->next;
        // 小心判断
        if(fast!=tail){
            fast = fast->next;
        }
    }
    // 中间结点就是慢指针
    ListNode* mid = slow;
    // 归并
    return merge(split(head, mid), split(mid, tail));
    
}

ListNode* sortList(ListNode* head){

    return split(head, nullptr);


}


int main(){
    ListNode* head = new ListNode(4);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(1);
    cur = cur->next;
    cur->next = new ListNode(3);

    ListNode* newHead = sortList(head);
    cur = newHead;
    while (cur!=nullptr)
    {
        /* code */
        cout<<cur->val<<endl;
        cur =cur->next;
    }
    
}