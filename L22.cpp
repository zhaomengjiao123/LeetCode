// 括号生成


// 能够生成所有可能的并且有效的括号组合

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

// 只有括号序列有效的时候才添加 （）
// 的那个左括号数量不大于n的时候添加左括号 同理 添加右括号


vector<string> ans;
string cur; // 当前小子集
void backtrack(int open, int end, int n){
    // 如果长度已经  是n的两倍了 说明  所有的括号已经就位 
    // 直接返回
    if (cur.size()==n*2)
    {
        ans.push_back(cur);
        return;
    }
    // 当左括号 数量不够的时候 放入左括号
    if (open < n)
    {
        cur.push_back('(');
        // 遍历下一个
        backtrack(open+1, end, n);
        // 弹出
        cur.pop_back();
    }
    // 同理查看右括号  要与左括号匹配  因此 数量必须小于 左括号的时候才能放入
    if (end<open)
    {
        // 放入右括号
        cur.push_back(')');
        backtrack(open, end+1, n);
        cur.pop_back();
    }
    
    
    


}

vector<string> generateParenthesis(int n) {
    if (n==1)
    {
        ans.push_back("()");
        return ans;
    }
    backtrack(0,0,n);
    return ans;
    


}

int main(){
    int n;
    cin>>n;
    vector<string> res = generateParenthesis(n);
    for (auto s:res)
    {
        /* code */
        cout<<s<<endl;
    }
    
}