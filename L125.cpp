// 验证是不是回文串


#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
using namespace std;
// 字母和数字都属于字母数字字符
bool isPalindrome(string s) {
    int n = s.size();
    if (n==0)
    {
        return true; // 空字符串属于回文串
    }
    
    int l = 0, r = n-1;
    while (l<=r)
    {
        // 判断是不是字母
        // cout<<isdigit(s[l])<<endl;
        if (!isdigit(s[l])&&!isalpha(s[l]))
        {
            l++;
            cout<<s[l]<<endl;
        }
        if (!isdigit(s[r])&&!isalpha(s[r]))
        {
             r--;   
        }
        
        if ((isdigit(s[l])||isalpha(s[l]))&&(isdigit(s[r])||isalpha(s[r])))
        {
            if (tolower(s[l])!=tolower(s[r]))
            {
                return false;
            }
            l++;
            r--;
            
        }  
    }
    return true;
    
        
}
int main(){
    string s;
    getline(cin,s);
    bool ans = isPalindrome(s);
    cout <<ans<<endl;
}