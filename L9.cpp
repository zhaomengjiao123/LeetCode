// 判断一个给定的数是不是回文数？

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


// 思路：获取每个位数上的数字，倒过来看
bool isPalindrome(long x) {
    long newX=0; // 新数
    long oldX = x;
    // 如果是负数  绝对不是
    if (x<0)
    {
        return false;
    }
    
    while (x!=0)
    {
        long cur = x%10;
        newX = newX*10 + cur;
        x = x/10;
    }

    if (newX==oldX)
    {
        return true;
    }
    return false;
    


    
    
        
}


int main(){
    int x;
    cin>>x;
    bool ans = isPalindrome(x);
    cout << ans <<endl;
}