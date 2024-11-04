// 单词搜索II
// n*n 返回所有可以找到的  单词  （并且在单词列表里）

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
#include<unordered_map>
#include<set>
using namespace std;


// 一个字符在同一个单词中只能用一次
// 官方：回溯+字典树
// 思路 ：

struct TrieNode
{
    unordered_map<char,TrieNode*> child;// 需要去重 所以 要用哈希表
    string word;
    TrieNode(){
        this->word="";
    }
};

void insertTrie(TrieNode* root, string & word){
    TrieNode* node = root;
    for (auto c:word)
    {
        // 如果子节点中没有这个 字符开头的字符串 则添加
        if (!node->child.count(c))
        {
         node->child[c]=new TrieNode();
        }
        node = node->child[c];
        
    }
    // 加入字符串  只有结尾才会加入  单词
    node->word = word;
    
}

// 四个方向
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 
bool dfs(vector<vector<char>>& board, int x, int y, TrieNode* root,
    set<string>& res){
        // 目前的字符
        char ch = board[x][y];// 先记录下来一会儿还要回溯
        // 如果字典树中没有  那肯定找不到
        if (!root->child.count(ch))
        {
            return false;
        }

        // 寻找子节点
        root = root->child[ch];
        // 把找到的前缀放入res
        if (root->word.size()>0)
        {
            res.insert(root->word);
        }
        // 改变当前位置 防止回头
        board[x][y]='#';
        // 开始查询四个方向
        for (int i = 0; i < 4; i++)
        {
            int nx = x+dirs[i][0];
            int ny = y+dirs[i][1];
            // 判断边界 不要溢出
            if (nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size())
            {
                // 跳过 已经看过的
                if (board[nx][ny]!='#')
                {
                    dfs(board,nx,ny,root,res);
                }
                
            }
            
        }
        // 回溯
        board[x][y]=ch;

        return true;
        
        
        


}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        set<string> res; // 找到的前缀？
        vector<string> ans;// 匹配的答案
        // 给要寻找的单词 构造字典树
        for (auto & word:words)
        {
            insertTrie(root, word);
        }
        // 遍历棋盘 寻找
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // 深度搜索每个点
                dfs(board,i,j,root,res);
                
            }
            
        }
    for (auto & word:res)
    {
        ans.emplace_back(word);
    }
    return ans;
        
        


}