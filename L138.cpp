/**
 * @file L138.cpp 随机链表的复制
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 复制 深拷贝
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 回溯+哈希表
/**
 * 具体思路：用哈希表记录每个节点对应的新节点的创建情况
 * 检查当前节点的后继结点  和  当前节点的随机指针指向的节点
 * 如果这两个节点有一个没有被创建  就递归的进行创建
 * 
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

unordered_map<Node*, Node*> cachedNode;

Node* copyRandomList(Node* head) {
    // 判断特殊情况  空链表直接返回
    if (head == nullptr) {
        return nullptr; /// 一直递归  直到空
    }
    if (!cachedNode.count(head))
    {
        /* code */
        // 如果没有  就创建一个新的节点  并将其添加到 哈希表中
        Node* headNew = new Node(head->val);
        // 添加到哈希表
        cachedNode[head]=headNew;
        headNew->next=copyRandomList(head->next);
        headNew->random=copyRandomList(head->random);


    }
    return cachedNode[head];
    
        
}