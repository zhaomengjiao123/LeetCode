// 给一个正整 求出他的二进制表示的位1的个数

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

// 十进制数转二进制的方式  除2取余法
// 每次将十进制数/2，余数就是当前二进制对应位上的数，
// 然后不断的把商/2，直到为0
int hammingWeight(int n) {
    int ans = 0;
    if (n==0)
    {
        return ans;
    }
    while (n!=0)
    {
        if (n%2==1)
        {
            ans++;
        }
        n = n/2;
        
    }
    return ans;
    
    
        
}

int main(){
    int n;
    cin>>n;
    int ans = hammingWeight(n);
    cout << ans<< endl;
}