// 快乐数：


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// 思路：用哈希表检测循环
// 三位数  不可能大于243 ，要么开始循环，要么跌到1
// 4位以及4位以上的数，每一步会丢失一位（不清楚是为什么？），直到降到3位为止
// 所以整体思路是：
// 找到给定的数字的下一个数字，然后使用hash判断是不是进入了循环  进入循环就直接返回

int getNext(int n){
    int sum = 0;
    // 得到每一个位上的数字
    while (n>0)
    {
        int d = n % 10;
        n =n / 10;
        sum = sum + pow(d,2);
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> st;
    // 当没有到1 并且集合中不存在这个数的时候  就添加
    // 如果已经存在这个数了  就说明进入了循环
    while (n!=1 && !st.count(n))
    {
        st.insert(n);
        // 找到下一个数
        n = getNext(n);
    }
    return n==1;
    




        
}

int main(){
    int n;
    cin>>n;
    bool ans = isHappy(n);
    cout << ans <<endl;
}