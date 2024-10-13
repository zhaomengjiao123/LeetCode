// 字符串解码

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

string getDigits(string &s, size_t &ptr){
    string  ret = "";
    while (isdigit(s[ptr]))
    {
        ret.push_back(s[ptr++]);
    }
    return ret;
    

}

// 串联 得到字符串
string getString(vector<string> &v){
    string ret;
    for (const auto &s:v)
    {
        ret=ret+s;
    }
    return ret;
    
}

string decodeString(string s) {
    vector<string> stk;
    size_t ptr=0;
    while (ptr<s.length())
    {
        char cur = s[ptr];
        if (isdigit(cur))
        {
            // 遇到数字了  开始进栈
            string digits = getDigits(s, ptr);
            stk.push_back(digits);
        }else if (isalpha(cur)||cur=='[')  // 这个函数用来检查是否是字母字符
        {
            // 字母 直接进站   构造一个新的字符串
            stk.push_back(string(1,s[ptr++]));
        }else{
            ptr++;
            vector<string> sub;
            // 开始出站匹配
            while (stk.back()!="[")
            {
                // 是字母？？？   括号  找到匹配的另一半
                sub.push_back(stk.back());
                stk.pop_back(); // 弹出这个元素
            }
            reverse(sub.begin(), sub.end());
            // 左括号出站
            stk.pop_back();
            // 此时栈顶的元素就对应了sub这个字符串出现的词素
            int repTime = stoi(stk.back());
            stk.pop_back();
            // 得到字符串
            string t,o = getString(sub);
            // 构造字符串
            while (repTime--)
            {
                t = t+ o;
            }
            stk.push_back(t);
            

            
        }
        
        
    }
    return getString(stk);

}