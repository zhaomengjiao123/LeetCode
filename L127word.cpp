// 单词接龙
// 每一对相邻的单词只差一个字母

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// BFS
// 建图：如果两个单词之间可以通过改变一个字母进行转换 那他们之间就有一条双向的边

unordered_map<string, int> wordId; // 给每个单词分配一个ID
vector<vector<int>> edge; //图 边
int nodeNum = 0;

void addWord(string& word){
    // 如果哈希表中每一张个单词 就加入这个单词 并且给他分配一个ID
    if (!wordId.count(word))
    {
        wordId[word]=nodeNum++;
        edge.emplace_back(); // 构造一个空的vetcor？
    }
    
}

void addEdge(string& word){
    // 构造边  先加入 单词表中国
    addWord(word);
    int id1 = wordId[word];
    // 遍历这个单词的每个字符
    for (char& it:word)
    {
        char tmp = it;
        it = '*'; // 创建这个word的变换一个字母的虚拟单词 *it，h*t,hi*
        addWord(word);
        int id2 = wordId[word];
        edge[id1].push_back(id2); // id1通过变换一个字母就可以达到的
        edge[id2].push_back(id1);
        it = tmp;
    }
    
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string& word:wordList)
        {
            // 添加边
            addEdge(word);
        }
        // 添加开始单词
        addEdge(beginWord);
        // 如果目标单词 不在哈希表中 说明无法达到
        if (!wordId.count(endWord))
        {
            return 0;
        }
        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord];
        int endId = wordId[endWord];
        dis[beginId]=0;

        queue<int> q;
        q.push(beginId);
        while (!q.empty())
        {
            // 遍历当前节点所有通过变换一次字符就可以达到的单词
            int nex = q.front();
            q.pop();
            if (nex==endId)
            {
                return dis[endId]/2+1; // 注意因为添加了虚拟节点，所以我们得到的距离为实际最短路径长度的两倍。同时我们并未计算起点对答案的贡献，所以我们应当返回距离的一半再加一的结果。???

            }
            
            // 否则的话遍历剩下的  相邻节点
            for (int& it:edge[nex])
            {
                if (dis[it]==INT_MAX)
                {
                    // 如果没有访问过  步数+1
                    dis[it]=dis[nex]+1;
                    q.push(it);
                }
                
            }
            
        }

        return 0;
        
        
        
}

int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int ans = ladderLength(beginWord, endWord, wordList);
    cout <<ans <<endl;
}
