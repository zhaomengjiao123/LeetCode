// 有效的字母异位词
// t 是否是 s的异位词？  原字幕只使用一次 重新排列得到的
// 只要对应的字母的数量一致即可

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


bool isAnagram(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int> sp(26);
    vector<int> tp(26);
    if (m!=n)
    {
        return false;
    }
    for (int i = 0; i < m; i++)
    {
        sp[s[i]-'a']++;
        tp[t[i]-'a']++;
    }

    if (sp==tp)
    {
        return true;
    }
    return false;
    
    
    
        
}

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;

    bool ans = isAnagram(s,t);
    cout << ans <<endl;

}