// 旋转链表
// 将链表的每个位置向右移动K个位置



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

// 向右移动k个位置 k%链表长度  其实就是截取链表后 k%长度 个节点  然后接到链表头上（链表的左边）


ListNode* rotateRight(ListNode* head, int k) {
    if (head==nullptr||head->next==nullptr||k==0)
    {
        return head;
    }
    
    // 计算链表的长度
    int le = 0;
    ListNode* cur = head;
    while (cur)
    {
        le++;
        cur=cur->next;
    }
    // 创建虚拟头结点
    ListNode* dummyNode = new ListNode(-1);
    dummyNode->next = head;
    cur = dummyNode;
    // 计算要截取的链表的长度
    int sub = k%le;
    if (sub==0)
    {
        return dummyNode->next;
    }
    
    for (int i = 0; i < le-sub; i++)
    {
        cur=cur->next;
    }
    // 现在cur 就是 要截取的节点的前一个节点

    ListNode* newHead = cur->next;
    // 找到尾结点
    ListNode* tail = newHead;
    for (int i = le-sub; i < le; i++)
    {
        tail = tail->next;
    }
    // 接回原链表
    // 还需要将原来的cur的next置空
    cur->next = nullptr;
    tail->next = dummyNode->next;
    dummyNode->next = newHead;

    return dummyNode->next;
    

    

    
        
}
