// 同构字符串


#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    int n = s.size();
    int m = t.size();
    if (m<n)
    {
        return false;
    }

    unordered_map<char, char> sdict; // 存储 s--t
    unordered_map<char, char> tdict; // 存储 t--s
    for (int i = 0; i < n; i++)
    {
        char s_cur = s[i];
        char t_cur = t[i];
        if (sdict.find(s_cur)==sdict.end()&&tdict.find(t_cur)==tdict.end())
        {
            // 只有当这个映射不存在的时候 才加入
            sdict[s_cur]=t_cur;
            tdict[t_cur]=s_cur;
        }else{
            if (sdict[s_cur]!=t_cur||tdict[t_cur]!=s_cur)
            {
                return false;
            }
            
        }
        

    }

    return true;
    

    

}

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    bool ans = isIsomorphic(s,t);
    cout <<ans<<endl;
}
        