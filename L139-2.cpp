// 单词拆分
// 一个字符串能否被  给出的字典中的字符串拼接出来
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
using namespace std;


// 动态规划 dp[i]代表给定字符串s 中从0-i是可以被字典中的字符串拼接出来的
// 那么 dp[i] = dp[j] && s[j...i]也在字典中
// 也就是找一个分割点 j dp[j]可以被拼接出来，并且剩下的部分j-i也在字典中
// 可能存在多个合适的分割点  但是找到一个就可以了


bool wordBreak(string s, vector<string>& wordDict){
    // 首先把字典存到哈希表中方便查找
    int n = s.size();
    unordered_set<string> mp;
    for(auto str:wordDict){
        mp.insert(str);
    }
    vector<bool> dp(n+1,false);
    // dp i 前i个字符串是否可以被拼接
    dp[0]=true;
    // 从第一个字符开始判断
    for(int i=1;i<=n;i++){
        // 寻找分割点j
        for(int j=0;j<i;j++){
            // 这个分割点需要符合的条件就是  分割点前面的j个字符串是可以被分割的
            // 也就是dp[j]=true ，并且剩下的字符串  j-i  在字典中是存在的
            if(dp[j] && mp.count(s.substr(j,i-j))>0){
                // 有分割点
                dp[i]=true;
                break;
            }
        }
    }

    return dp[n];

} 


int main(){
    string s;
    getline(cin, s);
    string words;
    getline(cin, words);
    stringstream ss(words);
    string word;
    vector<string> dict;
    while (ss>>word)
    {
        /* code */
        dict.push_back(word);
    }

    bool ans = wordBreak(s, dict);
    cout<<ans<<endl;
    

}