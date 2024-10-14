// 给定数字 返回能返回的字母的组合

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;

unordered_map<char, string> tele={
    {'2',"abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
vector<string> ans;
string t;// 每次的小子串

// 回溯
void backtrack(int index, string digits){
    // 当前填充到的位置index 因为 每个数字必须选一个因此只有等长 才会返回
    if (index==digits.length())
    {
        ans.push_back(t);
    }else{
        // 去数字
        char digit = digits[index];
        string te = tele[digit];
        cout<<"track te:"<< te<<endl;
        // 每个都放进去试一下
        for (int i = 0; i < te.length(); i++)
        {
            t.push_back(te[i]);
            // 遍历下一个位置
            backtrack(index+1, digits);
            // 回溯 弹出
            t.pop_back();
        }
        
    }

    
}

vector<string> letterCombinations(string digits) {
    int n = digits.length();
    // 判断特殊情况
    if (n==0)
    {
        return ans;
    }
    // 如果只有一位数
    if (n==1)
    {
        string te = tele[digits[0]];
        cout<<"te:"<<te<<endl;
        for (int i = 0; i < te.length(); i++)
        {
            ans.push_back(string(1,te[i]));
        }
        return ans;
        
    }
    // 两位及以上的数  
    // 因为要求的是 所表示的字母的组合，因此 每个数字中必须取一个字符
    backtrack(0, digits);
    return ans;
}

int main(){
    string digits;
    cin>>digits;
    cout<<digits<<endl;
    vector<string> ans = letterCombinations(digits);

    for (auto s:ans)
    {
        cout<<s<<" ";
    }
    
}