// X 的平方根
// 不能使用内置数学函数
// 只返回整数

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

// 二分查找 每次比较 mid 的平方hex的大小关系
int mySqrt(int x) {
   int l = 0, r=x, ans = -1;
   while (l<=r)
   {
     int mid = (r-l)/2 + l;
     // 比较平方值
     if ((long long)mid*mid<=x)
     {
        ans = mid;
         l =mid + 1;
     }else{
        r = mid-1;
     }
     
   }

   return ans;
   

        
}

int main(){
    int n;
    cin>>n;
    int ans = mySqrt(n);
    cout << ans <<endl;
}