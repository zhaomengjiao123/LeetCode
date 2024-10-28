// 判断给定的 a 能不能由b中的字符构成？b中的字符只能用一次

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;




bool canConstruct(string ransomNote, string magazine) {
    int n = ransomNote.size();
    int m = magazine.size();
    if (n>m)
    {
        // 肯定无法构成
        return false;
    }
    unordered_map<char,int> rmap;
    unordered_map<char,int> mmap;
    for (auto c:ransomNote)
    {
        rmap[c]++;
    }
    for (auto c:magazine)
    {
        mmap[c]++;
    }

    for (auto m:rmap)
    {
        if (mmap.find(m.first)==mmap.end()||mmap[m.first]<rmap[m.first])
        {
            return false;
        }
        
    }

    return true;
    
    
    
    
        
}

int main(){
    string rand;
    cin>>rand;
    string mas;
    cin>>mas;

    bool ans = canConstruct(rand, mas);

    cout << ans <<endl;
}