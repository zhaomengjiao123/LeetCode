/**
 * @file 2025ZiJie-4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/*
对于由n个整数组成的数组{a1 , a2,. . . , an}，定义“最大组合"为这样两个不同的位置i,j(1 ≤i,j≤n;i≠j)，使得ai和@j的最大公因数 gcd (ai , aj)为所有可能的i,j组合中的最大值。
现在，对于给定数组的全部前缀，求解每一个前缀中的“最大组合”"。更具体地，对于所有x (2≤x ≤n)，求解
{a1, a2,. . . , an}这个数组中，任意两数的最大公因数。
gcd，即最大公因数，指两个整数共有约数中最大的一个。例如，12和30的公约数有1,2,3,6，其中最大的约数是6,因此gcd(12,30)=6。
输入描述
第一行输入一个整数n(2≤n≤1e5）代表数组中的元素数量。
第二行输入n个整数a1,a2,... , an(1 ≤ai ≤1e5)代表数组中的元素。

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::gcd
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

vector<int> getFactors(int num){
    vector<int> factors;
    
    for (int i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            factors.push_back(i); // 添加因数
            if (i!=num/i){
                factors.push_back(num / i); // 添加对应的因数
            }
           
        }
    }
    sort(factors.begin(), factors.end()); // 排序因数
    return factors;
}

int main(){
    int n;
    cin >> n; // 输入数组长度
    vector<int> a(n); // 存储数组元素
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // 输入数组元素
    }

    unordered_map<int, int> factor_count;
    priority_queue<int> pq; // 大根堆 优先队列，用于存储gcd值
    unordered_set<int> pq_set; // 用于存储已访问的质因数
    vector<int> res; 
    int max_mod = 1e5+10;
    vector<int> cnt(max_mod,0); // 统计每个gcd值的出现次数
    int max_gcd = 0;
    
    for(int x=0;x<n;x++){
        int num = a[x];
        // gcd_count[num]++; // 统计当前数字的出现次数
        //质因数分解
        vector<int> factors = getFactors(num); // 获取当前数字的质因数

        // unordered_set<int> factors;
        // if(num==1){
        //     factors.insert(1);
        // }else{
        //     int tmp = num;
        //     for(int i=2;i*i<=tmp;i++){
        //         if(tmp%i==0){
        //             factors.insert(i); // 插入质因数
        //             while (tmp%i==0)
        //             {
        //                 /* code */
        //                 tmp /= i; // 除去质因数
        //             }
                    
        //         }
        //     }
        //     if (tmp>1) { // 如果num大于1，说明num本身是质数
        //         factors.insert(tmp); // 插入质因数
        //     }
        // }
        //更新质因数计数
        int cur_max = 0;

        for (auto f:factors)
        {
            if(f>=max_mod){
                continue; // 如果质因数大于max_mod，跳过
            }
            cnt[f]++;
            if(cnt[f]>=2 && f>cur_max){
                cur_max=f; // 更新当前最大gcd值
            }
            /* code */
            // if(factor_count[f]==0){
            //     pq.push(f); // 将质因数加入优先队列
            //     pq_set.insert(f); // 将质因数加入集合

            // }
            // factor_count[f]++;
            
        }
        if(x>=1){
            max_gcd = max(max_gcd,cur_max); // 更新当前最大gcd值
            res.push_back(max_gcd); // 将当前最大gcd值加入结果
            
        }
        
        // while (!pq.empty())
        // {
        //     int gcd = pq.top(); // 获取当前最大的gcd值
        //     if (factor_count[gcd] >=2) { 
        //         res.push_back(gcd); // 将当前gcd值加入结果
        //         break; // 找到一个有效的gcd值，退出循环
        //     }
        //     pq.pop();

        //     pq_set.erase(gcd); // 从集合中删除当前gcd值

            
        // }
       
        
        
    }
    for (auto ans:res)
    {
        /* code */
        cout << ans << " "; // 输出结果
    }
    

    return 0;
}
