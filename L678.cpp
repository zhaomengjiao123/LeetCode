/**
 * @file L678.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/**
 * 有效的括号字符串
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;


// 思路：分别统计左括号 右括号 和* 左括号和右括号如果数量不相等 ，* 可以补足就可以
// 又因为（必须在）之前，所以可以 用栈
// 因为我们用两个栈存储 （ 和 *  最后比较这两个的时候 不知道谁在前面，所以我们需要存储他们的下标
bool checkValidString(string s) {
    int n = s.size();
    stack<int> st;
    stack<int> star;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }else if (s[i]=='*')
        {
            /* code */
            star.push(i);
        } else {
            // ）
            // 每次找到右括号 踢出
            if(!st.empty()){
                st.pop();
            }else if(st.empty() && !star.empty()){
                // 如果左括号为空，但是*不为空
                star.pop();
            }else{
                // 如果左括号和*都为空
                return false;
            }
        }
    }
      // 最后检测剩下的* 和 （  先出来的必须是*  否则不行
        // 如果还有右括号，检测是不是和*数量相等 或 * 数量大于右括号
        if(!st.empty()){
            // 如果左括号不为空，但是*为空
            if(st.size()>star.size()){
                return false;
            }
            while (!st.empty())
            {
                /* code */
                if(st.top()<star.top()){
                    st.pop();
                    star.pop();
                }else{
                    return false;
                }
            }
            
        }
    return true;
        
 }

 int main(){
    string s= "(*))";
    bool ans = checkValidString(s);
    cout<<ans<<endl;
 }