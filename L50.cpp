// Pow（x，n）
// 计算 x的 n 次幂

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


// 只能想到笨方法  超时、、、、、哈哈哈
// 正确：快速幂+递归
// 快速幂：直接把上一次的结果平方 那么如果是偶数次平方，我们只需要计算一半,返回Res*res
// 如果是奇数次平方，我们需要 返回res*res*x
double quickMul (double x, long long n){
    if (n==0)
    {
        return 1.0;
    }
    double y = quickMul(x, n/2);
    if (n%2==0)
    {
        return y*y;
    }else{
        return y*y*x;
    }
    
    
}
double myPow(double x, int n) {
    // 如果是0次幂
    if (x==0)
    {
        return 0.0;
    }
    if (n==0 || x==1)
    {
        return 1.0;
    }
    int newNum = abs(n);
    double ans = quickMul(x, newNum);
    if (n<0)
    {
        return 1.0/ans;
    }
    
   
    return ans;
    
        
   
    
    
    
        
}

int main(){
    int n;
    double x;
    cin >> n;
    cin >>x;
    double ans = myPow(x,n);
    cout << ans <<endl;
}