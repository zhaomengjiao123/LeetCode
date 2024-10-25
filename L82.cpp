// 删除排序链表中的重复元素
// 删除所有重复元素，只留下本来就不同的数字


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


ListNode* deleteDuplicates(ListNode* head) {
    if (head==nullptr)
    {
        return head;
    }
    // 创建虚拟头结点
    unordered_map<int,int> nodeHash;// 存储节点上的值出现的次数
    ListNode* dummy = new ListNode(-1);
    dummy->next=head;
    ListNode* cur =head;
    while (cur)
    {
        nodeHash[cur->val]++;
        cur=cur->next;
    }
    cur = dummy;
    
    while (cur->next)
    {
        // 检查下一个节点的值是不是重复值
        if (nodeHash[cur->next->val]>1)
        {
            // 删除当前这个节点
            cur->next = cur->next->next;
        }else{
            cur = cur->next;
        }
        
    }

    return dummy->next;
    
    
        
}

