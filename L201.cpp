// 数字范围按位与

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

// 不能直接暴力算法 会超时
// 思考：就是求m和n的最长前缀？
// 因为按位与 只有两个对应的位置上都是1，最后对应的位置才可能为1
// 所以如果位数不相同的那些没必要看了？
int rangeBitwiseAnd(int left, int right) {
    if (left==right)
    {
        // 如果两个数相等，不用算了
        return left;
    }
    
    // 如果两个数的位数不同直接返回

    // 首先进行异或操作得到公共部分
    int res = left^right;
    int count = 0; // 记录0的个数
    // 从最高位开始统计0的个数
    for (int i = 31; i >= 0; i--)
    {
        if (res>>i==1)
        {
            // 如果右移 i 位  仍然是1
            break;
        }else{
            // 这是希望向右找到第一个不为1 的位置
            count++; // 记录0的个数
        }

        
        
    }
    count = 31 -count;
    return (left>>count)<<count; // 只保留右边的count位
    
    

    
        
}

int main(){
    int left;
    int right;
    cin>>left>>right;
    long long ans = rangeBitwiseAnd(left,right);
    cout << ans <<endl;
}