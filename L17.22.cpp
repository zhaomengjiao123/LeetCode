/**
 * @file L17.22.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/**
 * 字符串转换 但是每次只能转换一个字母，每一步得到的新词必须要在字典中中找得到
 */
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;


vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // 思路 ： 使用 BFS  相当于图，每次的转换就是一条边
    // 1. 先将wordList放入set中，方便查找
    unordered_set<string> wordSet(wordList.begin(),wordList.end());
    // 2. 如果endWord不在wordList中，直接返回空
    if(wordSet.find(endWord)==wordSet.end()){
        return {};
    }
    // 3. 用一个队列存储每一步的结果
    // 因为我们要找的是具体的转换路径，因此这里要存储vector<string>
    queue<vector<string>> q;
    q.push({beginWord});
    while (!q.empty())
    {
        // 当前的字符串是
        // 上一层存储的路径
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            /* code */
            vector<string> path = q.front();
            q.pop();
            // 这相当于下一层BFS的起点  路径的最后一个
            string cur = path.back();
            // 如果终点字符串和endWord相等，说明找到了
            if(cur==endWord){
                return path;
            }
             // 否则的话，遍历每一个字符
        for(int i=0;i<cur.size();i++){
            // 因为需要替换  所以  现将当前的字符存储起来
            char tmp = cur[i];
            // 替换当前字符
            for(char c='a';c<='z';c++){
                // 避免相同字符
                if(c==tmp){
                    continue;
                }
                cur[i]=c;
                // 如果替换后的字符在wordSet中，说明是有效的
                if(wordSet.count(cur)>0){
                    // 新的路径
                    vector<string> newPath = path;
                    newPath.push_back(cur);
                    q.push(newPath);
                    // 将替换后的字符放入队列中
                    wordSet.erase(cur);
                }
            }
            // 还原当前字符
            cur[i]=tmp;
            

        }
        }
    }
    return {};
    

        
}

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<string> res = findLadders(beginWord,endWord,wordList);
    for(auto s:res){
        cout<<s<<endl;
    }
    return 0;
}