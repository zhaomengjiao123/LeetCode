// 回文链表
// 判断一个链表是不是回文链表
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 判断
// 利用递归   先让一个指针递归到最后一个节点，然后这个节点从后往前比较

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){};
    ListNode(int x, ListNode* n):val(x), next(n){};
};

//让这个节点指针保持在前面
ListNode* front;
bool getAns(ListNode* cur){
    // 如果当前节点不存在，直接就是true
    if (cur!=nullptr)
    {
        // 查看下一个节点的匹配情况直到最后一个
        if(!getAns(cur->next)){
            // 下一个的节点如果有任何一个是不符合要求的，就不行
            return false;
        }
        // 如果已经是最后一个了（即当前节点的下一个节点是空的）
        // 就比较值
        if(cur->val!=front->val){
            return false;
        }
        // 为什么要把这个的后移动 放在里面？
        // 因为在外面就意味着是最后一个，最后一个不需要移动前面的指针
            front = front->next;

    }
    return true;  
}
bool isP(ListNode* head){
    front = head;
    return getAns(head);

}

int main(){
    // 构造链表
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(1);

    bool ans= isP(head);
    cout<<ans<<endl;
}