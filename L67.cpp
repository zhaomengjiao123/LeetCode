// 二进制求和
// 给定两个二进制形式的数，返回和  也是二进制的形式

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<sstream>
using namespace std;


string addBinary(string a, string b) {
    int aL = a.size();
    int bL = b.size();
    // 补足短的
    if (aL>bL)
    {
        for (int i = 0; i < aL-bL; i++)
        {
            b = "0"+b;
        }
        
    }
        if (aL<bL)
    {
        for (int i = 0; i < bL-aL; i++)
        {
            a = "0"+a;
        }
        
    }

    int n = a.size();
    int tmp = 0 ; // 保存进位
    string ans = "";
    for (int i = n-1; i >= 0; i--)
    {
        int cur = tmp + a[i]-'0'+b[i]-'0';
        int add = cur%2;

        ans = to_string(add)+ans;
        
        tmp = cur/2;
    }
    while (tmp!=0)
    {
        int add = tmp%2;
        ans = to_string(add)+ans;
        tmp = tmp/2;
    }

    return ans;
    
    
    
        
}

int main(){
    string a;
    string b;
    cin>>a>>b;
    string ans = addBinary(a,b);
    cout << ans <<endl;


}

