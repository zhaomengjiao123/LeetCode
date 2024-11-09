// 最大重复子字符串


#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


// KMP算法


int maxRepeating(string sequence, string word) {
    int n = sequence.size();
    int m = word.size();
    if (n<m)
    {
        return 0;
    }
    // 相当于KMP算法中的next数组？
    vector<int> fail(m,-1);
    for (int i = 1; i < m; i++)
    {
        int j = fail[i-1]; // 前一个公共前后缀的长度
        while (j!=-1 && word[j+1]!=word[i])
        {
            // 不匹配
            j = fail[j];
        }
        if(word[j+1]==word[i]){
            fail[i]=j+1;
        }
        
    }

    // 答案
    vector<int> f(n);
    int j=-1;
    // 遍历主字符串一遍，注意 i绝不后退
    for (int i = 0; i < n; i++)
    {
        while (j!=-1 && word[j+1]!=sequence[i])
        {
            j=fail[j];
        }
        // 如果下一个字符相同？
        if (word[j+1]==sequence[i])
        {
            j++;
            // 如果j已经到末尾了
            if (j==m-1)
            {
                f[i]=(i>=m?f[i-m]:0)+1; // f[i] 到i结尾的位置为止 有几个重复的word了？
                j=fail[j];
            }
            
        }
        
        
        
    }

    return *max_element(f.begin(),f.end());
    
    
    
   
        
}