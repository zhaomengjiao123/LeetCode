// 简化路径  将给定的路径转换为更简洁的规范路径



#include<iostream>
#include<algorithm>
#include<stack>
#include<sstream>
using namespace std;

// 思路：对于/ 只压入一个，然后获取//之间的路径，遇到..弹出，遇到.弹出
string simplifyPath(string path) {
    int n = path.size();
    stack<string> stk;
    for (int i = 0; i < n; i++)
    {
        if (path[i]=='/')
        {
            // 不能有连续的/
            if (i==n-1)
            {
                // 最后一个 不需要/
                continue;
            }else if (!stk.empty()&&stk.top()=="/")
            {
                continue;
            }else{
                stk.push("/");
                cout<<"i:"<<i<<endl;
            }
            
        }else{
            //开始读取一个字符串
            string tmp = "";
            while (i<n&&path[i]!='/')
            {
                tmp = tmp+path[i];
                i++;
            }
            // 超过了 减去
            i--;
            cout<<tmp<<endl;
            // 查看是不是.. .？
            if (tmp=="..")
            {
                //返回上级目录，先弹出栈顶 /
                if (!stk.empty()&&stk.top()=="/")
                {
                    cout<<"弹出："<<stk.top()<<endl;

                    stk.pop();
                }
                
                // 弹出上级目录
                if (!stk.empty())
                {
                    cout<<"弹出："<<stk.top()<<endl;

                    stk.pop();
                }

            }else if (tmp==".")
            {
                // 表示本级目录
                // 一直弹出到本级目录
                if (stk.top()=="/")
                {
                    cout<<"弹出："<<stk.top()<<endl;

                    stk.pop();
                }
                
            }else{
                stk.push(tmp);
                cout<<"push i:"<<i<<endl;
            }
        }

        
    }

    string ans = "";
    // 检查栈顶  不能是/
    if (!stk.empty()&&stk.top()=="/")
    {
        stk.pop();
    }
    
    while (!stk.empty())
    {
        ans = stk.top()+ans;
        stk.pop();
    }
    if (ans[0]!='/')
    {
        //添加
        ans = "/"+ans;
    }
    return ans;
    
    
    
        
}


int main(){
    string path;
    cin>>path;

    string ans = simplifyPath(path);
    cout<<ans<<endl;
}