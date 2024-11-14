// 找到数组中只出现一次的元素  其它的都出现了三次

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// 电路法？数字电路法
int singleNumber(vector<int>& nums) {
    int a =0,b=0;
    for (int num:nums)
    {
        tie(a,b)=pair{(~a&b&num)|(a&~b&~num),~a&(b^num)};
    }
    return b;
    
        
}