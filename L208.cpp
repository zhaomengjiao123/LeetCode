/**
 * @file L208.cpp 实现
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 前缀树
// 每个字符一层，
/**
 * @brief  指向子节点的指针数组 children。对于本题而言，数组长度为 26，即小写英文字母的数量。此时 children[0] 对应小写字母 a，children[1] 
 * 对应小写字母 b，…，children[25] 对应小写字母 z。
 * 布尔字段 isEnd，表示该节点是否为字符串的结尾。
 * 插入字符串

我们从字典树的根开始，插入字符串。对于当前字符对应的子节点，有两种情况：

子节点存在。沿着指针移动到子节点，继续处理下一个字符。
子节点不存在。创建一个新的子节点，记录在 children 数组的对应位置上，然后沿着指针移动到子节点，继续搜索下一个字符。
重复以上步骤，直到处理字符串的最后一个字符，然后将当前节点标记为字符串的结尾。
 */
#include<vector>
#include<sstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Trie{
    private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix){
        // 查找字符串中是否有这个 前缀
        Trie* node = this;
        for (char ch: prefix)
        {
            // 每个字符的位置 -‘a'
            ch = ch - 'a';
            // 看看节点中是否存在
            if (node->children[ch]==nullptr)
            {
                // 不存咋
                return nullptr;
            }
            // 如果存在  就继续检索下一个
            node = node->children[ch];

            
        }
        return node;
        
    }

    public:
    Trie(): children(26),isEnd(false) {}

    
    void insert(string word) {
        // 插入到前缀树中
        Trie* node = this;
        // 看看树里面有没有，有的话直接插入，没有的话新建
        for (char ch:word)
        {
              ch = ch - 'a';
        if (node->children[ch]==nullptr)
        {
            // 新建一个
            node->children[ch] = new Trie();
        }
        // 下一个
        node = node->children[ch];
        }
        // 标记结束位置
        node->isEnd = true;
    }
    
bool search(string word) {
    Trie* node = this->searchPrefix(word);
    // 先找到前缀节点 然后看存不存在，存在的话是不是结束了
    return node!=nullptr && node->isEnd;

}
    
bool startsWith(string prefix) {
    return this->searchPrefix(prefix)!=nullptr;

}
}


T