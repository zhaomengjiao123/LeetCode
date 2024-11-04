// 给定一个整数组成的 非空数组所表示的非负整数
// 在该数的基础上+1


#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


// 先计算得到原数 + 1
// 再拆分  不行！！！溢出了
// 那就先倒序 然后逐个位判断
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    reverse(digits.begin(), digits.end());

    int tmp = 0; // 表示进位
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        if (i==0)
        {
        cur = digits[i]+tmp+1;
        }else{
            cur = digits[i]+tmp;
        }
        // 进位 
        tmp = cur/10;
        cur = cur%10;
        digits[i]=cur;
        
    }
    // 如果还有进位
    if (tmp>0)
    {
        digits.push_back(tmp);
    }
    // 倒序回来
    reverse(digits.begin(),digits.end());

    return digits;
    
   
    
        
}

int main(){
    vector<int> nums = {1,2,3};
    vector<int> ans = plusOne(nums);
    for (auto n:ans)
    {
        cout << n << " ";
    }
    
}