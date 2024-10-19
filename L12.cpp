// 整数转罗马数字


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;


unordered_map<int, string> map = {
    {1,"I"},
    {2,"II"},
    {3,"III"},
    {4,"IV"},
    {5,"V"},
    {6,"VI"},
    {7,"VII"},
    {8,"VIII"},
    {9,"IX"},
    {10,"X"},
    {40,"XL"},
    {50,"L"},
    {90,"XC"},
    {100,"C"},
    {400,"CD"},
    {500,"D"},
    {900,"CM"},
    {1000,"M"}

};

string intToRoman(int num) {
    // 题目要求：1 <= num <= 3999
    string ans="";

    int m = num / 1000;
    // m不可能大于3
    for (int i = 0; i < m; i++)
    {
        ans =ans + map[1000];
    }
    num = num % 1000;
    int n = num / 100;
    if (n==9||n==4||n==1||n==5)
    {
        ans =ans + map[n*100];
    }else{
        if (n<4)
        {
            for (int i = 0; i < n; i++)
            {
                ans = ans + map[100];
            }
            
        }else{
            ans = ans + map[500];
            for (int i = 0; i < n-5; i++)
            {
                ans = ans + map[100];
            }
            
        }
        
    }

    num = num % 100;
    // 处理十位数
    int t = num / 10;
    if (t==4||t==9||t==5||t==1)
    {
        ans =ans + map[t*10];
    }else{
        if (t<4)
        {
            for (int i = 0; i < t; i++)
            {
                ans = ans + map[10];
            }
            
        }else{
            ans = ans + map[50];
            for (int i = 0; i < t-5; i++)
            {
                ans = ans + map[10];
            }
            
        }
        
    }
    // 处理个位数
    int g = num%10;
    ans = ans + map[g];

    return ans;
    
    
    
    
    
        
}

int main(){
    int num;
    cin >> num;
    string ans = intToRoman(num);

    cout << ans << endl;
}