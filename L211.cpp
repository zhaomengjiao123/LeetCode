// 添加与搜索单词
// 设计一个数据结构 支持添加新单词 和 查找字符串是否与任何先前添加的字符串匹配


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_map>
using namespace std;

// 思路 字典树？ 是的
// 需要实现字典树的数据结构
struct TrieNode
{
    // 孩子节点
    vector<TrieNode*> child;
    bool isEnd;
    TrieNode(){
        // 初始化 26个空位 因为有26个字母
        this->child=vector<TrieNode*>(26,nullptr);
        this->isEnd=false;
    }
};


// 字典树中插入  单词
void insert(TrieNode* root, const string & word){
    TrieNode* node = root;
    // 先查找每个字符在字典树中有没有
    for (auto c:word)
    {
        c = c-'a';
        if (node->child[c]==nullptr)
        {
            // 添加新的节点
            node->child[c]=new TrieNode();
        }
        // 递归下一个
        node  = node->child[c];
        
    }
    // 单词的结束标记
    node->isEnd = true;
    
}

class WordDictionary {
    TrieNode* trie;    
    

public:
    WordDictionary() {
        // 初始化一个字典树
        trie = new TrieNode();
        
    }
    
    void addWord(string word) {
        // 向字典树中添加单词
        insert(trie, word);
        
    }
    
    bool search(string word) {
        return dfs(word, 0, trie);

        
    }
    // 递归搜索字典树
    bool dfs(const string & word, int index, TrieNode* node){
        // 如果递归到单词的最后一个 查看是不是单词的结束
        if (index==word.size())
        {
            return node->isEnd;
        }
        // 否则 查询

        char ch = word[index];
        // 查看是不是26个字母？
        if (ch>='a'&&ch<='z')
        {
            // 查询有没有
            TrieNode* child = node->child[ch-'a'];
            if (child!=nullptr && dfs(word,index+1,child))
            {
                // 递归下一个字符
                return true;
            }
            
        }else if(ch=='.'){
            // . 只要有子节点就可以
            // 直接查询子节点只要不为空就可以了
            for (int i = 0; i < 26; i++)
            {
                TrieNode* child = node->child[i];
                if (child!=nullptr&&dfs(word,index+1,child))
                {
                    return true;
                }
                
            }
            

        }

        // 都是空的 假的
        return false;
        

        
    }
};
