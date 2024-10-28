// 找出字符串 中第一个匹配项的下标


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;



int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i < n; i++)
    {
        if (haystack[i]==needle[0])
        {
            // 找到第一个字母的匹配
            // 直接截取字符串比较
            if (i+m<=n)
            {
                string tmp = haystack.substr(i,m);
                if (tmp==needle)
                {
                    return i;
                }
                
            }else{
                // 长度已经不够了 不可能相等了  结束
                return -1;
            }
            
        }
        
    }

    return -1;
    
        
}

int main(){
    string h, n;
    cin>>h;
    cin>>n;
    int ans = strStr(h,n);
    cout << ans <<endl;
}