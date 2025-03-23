/**
 * @file L146.cpp  LRU 缓存
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/**
 * LRU (最近最少使用) 缓存 约束的数据结构。
 * 放弃醉酒没有使用的关键字   姚集鲁每个关键字最后一次使用的时间
 */
/**
 * 哈希表  +  双向链表
 * 双向链表 ：  按照使用的顺序存储键值对  靠近头部的事最近使用的   靠近尾部的是最久没有被使用的
 * 哈希表：缓存数据键映射到其在双向链表中的位置
 * 
 * 使用哈希表找到在链表中位置，并将其移动到双向链表的头部
 * 
 * 在双向链表的实现中，使用一个伪头部（dummy head）和伪尾部（dummy tail）标记界限，
 * 这样在添加节点和删除节点的时候就不需要检查相邻的节点是否存在。
 */
#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

// 双向链表
struct DLinkedNode
{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key, int _value):key(_key), value(_value),prev(nullptr), next(nullptr){}

};
class LRUCache
{
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
public:
LRUCache(int _capacity):capacity(_capacity), size(0) {
    // 使用伪头部和伪尾部节点
    head = new DLinkedNode();
    tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
    // 初始化  一开始链表中就只有伪头部和伪尾部两个节点
}
    
int get(int key) {
    // 先检查 哈希表中有没有这个数据
    if (!cache.count(key))
    {
        /* code */
        // 没有的话  说明没有存入 返回-1  查询失败
        return -1;
    }
    // 如果存在  就需要将其移动到双向链表的头部  代表刚被访问过
    DLinkedNode* node = cache[key];
    moveToHead(node);
    return node->value;
}
    
void put(int key, int value) {
    // 先看链表中是否已经存在了？
    if (!cache.count(key))
    {
        /* code */
        // 如果不存在  那么插入  同时别忘了检查容量是否够用
        DLinkedNode* node = new DLinkedNode(key, value);
        // 添加到哈希表中
        cache[key] = node;
        // 添加到链表的头部
        addToHead(node);
        // 标记容量
        size++;
        // 检查是否溢出  溢出的话  删除尾部的节点
        if (size>capacity)
        {
            /* code */
            DLinkedNode* removed = removeTail();
            // 删除哈希表中对应的项
            cache.erase(removed->key);
            // 删除  这个节点  防止内存泄露  同时减小链表大小
            delete removed;
            size--;

        }
        
    }else{
        //如果已经存在  将其移动到链表的头部  比忘了要修改value
        DLinkedNode* node=cache[key];
        node->value=value;
        moveToHead(node);
    }  

}

// 讲一个节点添加到链表的头部
 void addToHead(DLinkedNode* node){
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
 }
 // 将链表的节点移除
 void removeNode(DLinkedNode* node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
 }
 // 将一个节点移动到链表的头部
 void moveToHead(DLinkedNode* node){
    removeNode(node);
    addToHead(node);
 }
 // 将链表尾部的节点删除
 DLinkedNode* removeTail(){
    DLinkedNode* node = tail->prev;
    removeNode(node);
    return node; // 为什么要返回？ 是不是因为哈希表中也要同时删除这个节点
 }
    
};

int main(){
    LRUCache test(2);
    test.put(1,1);
    test.put(2,2);
    cout<<test.get(1)<<endl;
    test.put(3,3);
    cout<<test.get(2)<<endl;
    test.put(4,4);
    cout<<test.get(1)<<endl;
    cout<<test.get(3)<<endl;
    cout<<test.get(4)<<endl;
}