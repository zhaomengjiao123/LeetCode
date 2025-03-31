/**
 * @file 2025ZiJie-2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/**
 * 对于给定的仅由字符‘o〉和‘1〉组成的字符串s，新建一个空字符串t，随后，将s加入到字符串t的末尾，如此重复n次。
求t中子序列恰好为"01”的数量。由于答案可能很大，请将答案对(10°＋7)取模后输出。
子序列为从原字符串中删除任意个（可以为零、可以为全部)字符得到的新字符串。
输入描述
每个测试文件均包含多组测试数据。第一行输入一个整数
T(1≤T≤105）代表数据组数，每组测试数据描述如下:
在一行上输入一个长度为1≤len(s) ≤105，仅由字符‘0'和‘1〉组成的字符串s。随后在同一行上输入一个整数
n(1≤n≤1018)代表复制次数。

 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <sstream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        long long n;
        cin>>s>>n;
        long long cnt0=0,cnt1=0;
        long long ones = 0;
        long long single = 0; // 每个0后面的1的数量和
        // 从后往前计算每个0后面有多少个1
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                ones++;
            }else{
                single += ones; // 计算当前0后面有多少个1
            }
            if(s[i]=='0'){
                cnt0++;
            }else{
                cnt1++;
            }
        }
        int mod = 1e9+7;
        int inv2 = 500000004; // 2的模逆元  大数除法
        // 单个字符串内部的共线
        long long t1 = ((single%(int)(1e9+7))*(n%(int)(1e9+7)))%mod; // 计算单个字符串内部的共线
        // 计算跨字符串的共线
        long long t2 = (cnt0%mod)*(cnt1%mod)%mod;

        long long mm = (n%mod)*((n-1)%mod)%mod;
        mm = mm*inv2%mod; // 计算跨字符串的共线
        t2 = t2*mm%mod; // 计算跨字符串的共线
        long long ans = (t1+t2)%mod; // 计算总的共线
        
        cout<<ans<<endl;
    }

}