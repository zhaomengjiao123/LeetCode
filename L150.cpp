// 逆波兰表达式求值  后缀表达式求值

// 优点 去掉括号后表达没有歧义
// （1+2）-3  这种平常用的是  中缀表达式

#include<iostream>
#include<vector>
#include<sstream>
#include<stack>
#include<algorithm>
using namespace std;


// 逆波兰表达式  求值 思路：遇到数字就入栈，遇到表达式就弹出栈顶的前两个元素进行
// 计算，再把结果入栈

int evalRPN(vector<string>& tokens) {
    int n = tokens.size();
    stack<int> stk;
    if (n==0)
    {
        return 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"||tokens[i]=="*")
        {
            // 弹出栈顶的2个元素进行运算
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            if (tokens[i]=="+")
            {
                stk.push(a+b);
            }else if (tokens[i]=="-")
            {
                stk.push(b-a);
            }else if (tokens[i]=="/")
            {
                stk.push(b/a);
            }else if (tokens[i]=="*")
            {
                stk.push(a*b);
            }  
        }else{
            // 是数字  直接入栈
            stk.push(stoi(tokens[i]));
        }
        
    }

    return stk.top();
    
        
}


int main(){
    vector<string> tokens = {
        "4","13","5","/","+"
    };
    int ans = evalRPN(tokens);

    cout << ans << endl;

}
