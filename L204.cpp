// 计数质数  返回所有小于n的质数的数量

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;

// 方法化 题目  使用埃氏筛

// 埃氏筛：如果x是质数，那么x的倍数2x,3x....x*x 肯定不是质数，从x*x遍历，因为2x,3x。。肯定在遍历2 3的时候已经筛过了

int countPrimes(int n) {
    vector<int> isPrime(n,1); // 都先标记为是质数
    int ans = 0; // 质数计数
    // 0 1 不是质数 因此从2开始
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            // 如果是质数 答案+1
            ans = ans +1;
            cout << i <<endl;
            // 遍历倍数 标记合数
            if ((long long)i*i<n)
            {
                for (int j = i*i; j < n; j = j+ i)// 因为要找i的倍数，因此每次递增i
                {
                    isPrime[j]=0; // 标记为合数
                }
                
            }
            
        }
        
    }
    

    return ans;
        
}

int main(){
    int n;
    cin>>n;
    int ans = countPrimes(n);
    cout << ans <<endl;
}