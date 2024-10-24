// 判断子序列？
// 判断 s是不是t的子序列？

#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


bool isSubsequence(string s, string t) {
    // 双指针 遍历检查
    int n = s.size();
    int m = t.size();
    if (n>m)
    {
        return false;
    }
    if (n==0)
    {
        return true;
    }
    int sl = 0, tl=0;
    while (sl<n&&tl<m)
    {
        if (s[sl]==t[tl])
        {
            sl++;
            tl++;
        }else{
            tl++;
        }
        
    }

    if (sl==n)
    {
        return true;
    }else{
        return false;
    }      
}

int main(){
    string s, t;
    getline(cin,s);
    getline(cin,t);
    bool ans = isSubsequence(s,t);
    cout << ans <<endl;
}