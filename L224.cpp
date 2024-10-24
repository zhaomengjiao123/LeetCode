// 基本计算器

//给一个字符串 计算他的值

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;


// 字符串中只包含 + - （）

int calculate(string s) {
    int n = s.size();
    stack<char> stk;
    int ans = 0, num = 0, op = 1; // op代表当前的操作符，如果是1代表+，-1代表减
    stk.push(op);
    for (char cur:s)
    {
        // 跳过空格
        if (cur==' ')
        {
            continue;
        }
        if (cur>='0'&&cur<='9')
        {
            // 处理数字  因为有可能是多位数因此要乘10
            // 计算当前的数字
            num = num * 10 + (cur-'0');
        }else{
            // 是操作符或者括号
            // 将当前的操作符合括号应用到结果中
            ans = ans + op*num;
            // 重置数字
            num = 0;
            if (cur=='+')
            {
                op = stk.top();
            }else if (cur=='-')
            {
                op = -stk.top();
            }else if (cur=='(')
            {
                // 如果是左括号 直接压入操作符
                stk.push(op);
            }else{
                // 右括号  代表计算完一个操作服了  ，弹出
                stk.pop();
            }
            
            
            
        }
        
        
    }
    


    return ans+op*num;
     
    
}

int main(){
    string s;
    cin >>s;
    int ans = calculate(s);
    cout<<ans <<endl;
}