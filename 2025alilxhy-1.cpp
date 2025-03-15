#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


bool check(string s) {
        // write code here
        // 思路：使用栈
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='['||c=='{'){
            // 压入栈
            st.push(c);
        }else if(c==')'||c==']'||c=='}'){
            if(st.empty()){
                return false;
            }
            char top = st.top();
            if((c==')'&&top=='(') ||(c==']'&&top==']')||(c=='}'&&top=='{')){
                st.pop();
            }else{
                return false;
            }
        }
    }

    if(st.empty()){
        return true;
    }else{
        return false;
    }
        

    }