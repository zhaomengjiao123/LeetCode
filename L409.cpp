// 最长的回文子串  区分大小写
// 用给定的字符串构造回文串  寻找长度

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
using namespace std;

// 思路 ：哈希，只要个数是偶数，就可以作为回文串的一部分
// 有奇数的话，可以在中间加一个字符，剩余的偶数部分作为回文串的一部分
int longestPalindrome(string s) {
    int n = s.size();
    if (n==0||n==1)
    {
        return n;
    }
    if (n==2)
    {
        return s[0]==s[1]?2:1;
    }

    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    // 遍历哈希表
    int ans = 0;
    // 是否有单数的
    bool flag = false;
    for (auto term:mp)
    {
        if (term.second%2==0)
        {
            ans = ans + term.second;
        }else{
            flag = true;
            ans = ans + term.second-1;
        }
        
    }
    if (flag)
    {
        // 可以在中间加上一个字符
        ans = ans +1;
    }
    

    return ans;
    
    
    
    
        
}

int main(){
    string s;
    cin>>s;
    int ans = longestPalindrome(s);
    cout << ans << endl;
}