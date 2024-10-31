// 字符串相加  两个以字符串表示的大数相加，以字符串的形式返回


#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
using namespace std;


string addStrings(string num1, string num2) {
    int n = num1.size();
    int m = num2.size();

    string ans = "";
    // 将两个字符串补同样长
    if (m>n)
    {
        num1 = string(m-n,'0')+num1;
    }
    if (n>m)
    {
        num2 = string(n-m,'0')+num2;
    }
    cout << num1 <<" "<< num2 <<endl;
    
    int len = max(n,m);

    int tmp = 0;
    for (int i = len-1; i >= 0; i--)
    {
        int cur1 = num1[i]-'0';
        int cur2 = num2[i]-'0';
        cout <<cur1 <<" "<<cur2<<endl;
        int now = cur1+cur2+tmp;
        tmp = now / 10;
        cout << now<<" "<<tmp<<endl;

        ans = to_string(now%10)+ans;
        cout << ans<<endl;
    }
    // 查看有没有剩下的？
    if (tmp!=0)
    {
        ans = to_string(tmp)+ans;
    }
    return ans;
    
    
    
        
}

int main(){
    string s1;
    string s2;
    cin >>s1;
    cin>>s2;

    string ans = addStrings(s1,s2);
    cout << ans <<endl;
}