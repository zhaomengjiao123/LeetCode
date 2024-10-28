// 单词规律：  给定一种规律和一个字符串  判断字符串是不是遵守相同的规律？
// 规律中的每个字符 和  字符串中的每个单词有双向链接的对应规律

// 和之前的哪个  对应  转换一样的思路

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<sstream>
using namespace std;


bool wordPattern(string pattern, string s) {
    vector<string> words;
    string word;
    stringstream ss(s);
    while (ss>>word)
    {
        cout << word <<endl;
        words.push_back(word);
    }
    cout <<words.size()<<endl;
    if (words.size()!=pattern.size())
    {
        return false;
    }
    // 遍历构建哈希表
    unordered_map<char, string> pmap; // p -- word
    unordered_map<string, char> smap; // word--p
    for (int i = 0; i < pattern.size(); i++)
    {
        if (pmap.find(pattern[i])==pmap.end()&&smap.find(words[i])==smap.end())
        {
            // 2个 都不存在  插入
            pmap[pattern[i]]=words[i];
            smap[words[i]]=pattern[i];
            cout << smap[words[i]] <<" "<<pattern[i]<<endl;
        }else{
            if (pmap[pattern[i]]!=words[i]||smap[words[i]]!=pattern[i])
            {
                cout << "pmap:"<<pmap[pattern[i]]<<" word:"<<words[i]<<endl;
                cout << "smap:"<<smap[words[i]]<<" p:"<<pattern[i]<<endl;

                return false;
            }
            
        }
        
    }

    return true;
    
    
    
        
}

int main(){
    string p;
    string s;
    getline(cin,p);
    getline(cin,s);

    bool ans = wordPattern(p,s);
    cout <<ans <<endl;

}