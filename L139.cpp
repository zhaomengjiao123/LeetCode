/**
 * @file L139.cpp 单词拆分
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<sstream>
using namespace std;

/**
 * DFS +回溯
 */

bool wordBreak(string s, vector<string>& wordDict) {
    // 先将字典存储为哈希表  方便查找
    auto wordDictSet = unordered_set<string> ();
    for (auto word: wordDict)
    {
        /* code */
        wordDictSet.insert(word);
    }
    /**
     * dp[i]  表示以 s[i] 为结尾的字符串是否合法，
     * 看 dp[j] j<i 是否合法 以及  j-i是否合法  如果都合法 那么dp[i]就合法
     *   因为是前 i 个字符  那前0个字符  不需要任何字符 肯定是可以拼出来的
     */
    auto dp =vector<bool> (s.size()+1); // ? 为啥+1  
    // 初始化 前０个字符　　空字符串　肯定可以拼出来
    dp[0]=true;
    // 开始遍历  从1开始 因为 前1个字符  并且注意最后是 <= s.size() 因为定义的i是前i个字符
    for (int i = 1; i <= s.size(); i++)
    {
        /* code */
        /// 查找 中间分割点 j
        for (int j = 0; j < i; j++)
        {
            /* code */
            // dp j 可以找到  并且剩下的部分也可以被找到
            if (dp[j] && wordDictSet.find(s.substr(j,i-j))!=wordDictSet.end())
            {
                /* code */
                dp[i]=true;
                // 有一个分割点符合要求即可，不再继续寻找
                break;
            }
            
        }
        

    }
    // 返回最后一位
    return dp[s.size()];
}

int main() {
    string s;
    vector<string> wordDict;
    string word;

    getline(cin, s);
    getline(cin, word);

    stringstream ss(word);
    string w;
    while (ss >> w)
    {
        /* code */
        wordDict.push_back(w);
    }

    bool ans = wordBreak(s, wordDict);

    cout << ans << endl;
    

}