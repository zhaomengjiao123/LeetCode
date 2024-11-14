// 颠倒二进制位
// 颠倒给定的32位无符号整数的二进制位

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    // 从最低位枚举？
    for (int i = 0; i < 32 & n>0; i++)
    {
       res |= (n&1)<<(31-i); 
       n>>=1;
    }
    return res;
    
        
}