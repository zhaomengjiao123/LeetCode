// 给定字符串  反转字符串中的单词的顺序

// 输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。


#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


string reverseWords(string s) {
    stringstream ss(s);
    vector<string> map;
    string tmp;
    while (ss>>tmp)
    {
        map.push_back(tmp);
    }
    int n = map.size();
    string ans="";
    for (int i=n-1;i>=0;i--)
    {
        if (ans.length()==0)
        {
            ans = ans + map[i];

        }else{
            ans = ans + " "+map[i];
        }
        
    }
    return ans;
    
    
        
}