// 分割回文串
// 要求分割额子串都是回文串  返回所有分割方案


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

// 回溯+动态规划
vector<vector<int>> f; // f i j  表示是否是回文串
vector<vector<string>> ret;
vector<string> ans;
int n;

// 回溯，，添加下一个字符后看看是不是回文串 不是就回溯，是的话继续

// 结束的条件是  index等于长度 或者  当前的不是回文串
void backtrack(string& s, int i){
    if (i==n)
    {
        ret.push_back(ans);
        return;
    }
    for (int j = i; j < n; j++)
    {
        // 是回文串  在进行
        if (f[i][j])
        {
            // 把这个回文串放入解集
            ans.push_back(s.substr(i,j-i+1));
            backtrack(s, j+1);
            // 回溯
            ans.pop_back();
        }
        
    }
}

vector<vector<string>> partition(string s) {
    // 按长度划分？
    n =s.size();
    f.assign(n, vector<int>(n, true));
    // 填充  回文串判断
    for (int i = n-1; i >=0; i--)
    {
        for (int j = i+1; j < n; j++)
        {
            f[i][j]=(s[i]==s[j]&&f[i+1][j-1]);
        }
        
    }
    backtrack(s,0);
    return ret;
    

    

    
    
    

}

int main(){
    string s;
    getline(cin, s);

    vector<vector<string>> res = partition(s);
    for (auto a:res)
    {
        for (auto b:a)
        {
            cout << b << endl;
        }
        
    }
    
}