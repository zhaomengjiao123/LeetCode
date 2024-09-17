/**
 * @file L438.cpp 找到字符串中给定字符串的所有字母异位词的起始索引
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

// 超出时间限制 可能是因为使用了sort
// vector<int> findAnagrams(string s, string p) {
//     // 先把p排序
//     sort(p.begin(), p.end());
//     int pl= p.size();
//     int right = -1;
//     int n = s.size();
//     vector<int> ans;

//     for (int i = 0; i < n-pl+1; i++)
//     {
//         /* code */

//         // 截取当前坐标 并且长度为p的长度 的字符串
//         string substr = s.substr(i,pl);
//         sort(substr.begin(), substr.end());
//         // 比较是否相等  
//         if (substr == p)
//         {
//             /* code */
//             // 是异位词  记录其实坐标
//             ans.push_back(i);
//         }
        
//     }
//     return ans;

// }
vector<int> findAnagrams(string s, string p) {
    // 把ｐ　存起来

    int pl= p.size();
    int n = s.size();
    unordered_set<char> pSet;
    vector<int> ans;


    // 先判断特殊情况，如果  s的长度小于p那么一定无法构造
    if (n < pl)
    {
        /* code */
        return ans;
    }
    vector<int> sCount(26);
    vector<int> pCount(26);
    // 将每个字母的数量存储  只要每个字母的数量相同即可
    // 也算是初始化了一个长度为pl 的滑动窗口
    for (int i = 0; i < pl; i++)
    {
        /* code */
        sCount[s[i]-'a']++;
        pCount[p[i]-'a']++;
    }
    // 如果这个就相同了，那么就找到一个
    if (sCount == pCount)
    {
        /* code */
        ans.push_back(0);
    }
    // 维持滑动窗口
    for (int i = 0; i < n-pl; i++)
    {
        /* code */
        // 左侧指针向右滑动的过程中，把相应字母的数量减少
        sCount[s[i]-'a']--;
        sCount[s[i+pl]-'a']++;

        // 如果在这个过程中相等了，就找到了
        if (sCount == pCount)
        {
            /* code */
            ans.push_back(i+1);
        }
        
    }
    return ans;

}



int main(){
    string str;
    string p;
    cin>> str >> p;
    vector<int> ans = findAnagrams(str, p);

    for (int i = 0; i < ans.size(); i++)
    {
        /* code */
        cout << ans[i] << " ";
    }
    cout<<endl;
    
}

