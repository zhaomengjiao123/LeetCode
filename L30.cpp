// 串联所有单词的子串

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// 我的思路是吧words存储起来，然后从 s截取等长字符串检查
vector<int> findSubstring(string s, vector<string>& words) {
    // 先存储words
    int m = words.size();
    int n = words[0].size();
    int ls =s.size();
   
    vector<int> ans;
    // 从第一个字符开始循环，查找所有可能作为起点的字母，总长度的最后一个  起码不要超过s的总长度
    for (int i = 0; i < n && i + m*n <=ls; i++)
    {
        // 统计当前窗口内的单词出现的次数
        unordered_map<string, int> differ;
        // 从起始位置开始的 m 哥单词
        for (int j = 0; j < m; j++)
        {
            differ[s.substr(i+j*n,n)]++;
        }
        // 遍历  word中的每个单词，检查在 differ中出现的次数
        for (string &word:words)
        {
            if (--differ[word]==0)
            {
                // 如果出现的次数变为0，就从differ删除
                differ.erase(word);
            }
            
        }
        // 内层循环 开始滑动窗口  每次移动一个单词的距离
        for (int start = i; start < ls-m*n+1; start+=n)
        {
            if (start!=i)
            {
                // 添加新进入窗口的单词 到 differ中
                string word = s.substr(start+(m-1)*n,n);
                if (++differ[word]==0)
                {
                    differ.erase(word);
                }
                // 移除窗口左侧 移出的单词
                word = s.substr(start-n,n);
                if (--differ[word]==0)
                {
                    differ.erase(word);
                }

                
                
            }

            // 如果differ为空就表示　当前的窗口符合要求
            if (differ.empty())
            {
                ans.emplace_back(start);
            }
            
            
        }
        
        
        
    }
    

    return ans;
    
    
        
}

int main(){
    string s;
    vector<string> words;
    getline(cin,s);
    string ww;
    getline(cin,ww);

    stringstream ss(ww);
    string cur;
    while (ss>>cur)
    {
        words.push_back(cur);
    }

    vector<int> ans = findSubstring(s, words);

    for (auto i : ans)
    {
        cout << i << endl;
    }
    
    
}