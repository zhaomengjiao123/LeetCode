// 有效的括号
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> ans;
    int n = s.size();
    // 前半截括号都亚茹栈中
    
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='('||s[i]=='['||s[i]=='{')
        {
            ans.push(s[i]);
        }else{
            if (ans.size()==0)
            {
                return false;
            }
            
            char now = ans.top();
            ans.pop();
            cout<< " now:"<< now << " s[i]:"<<s[i]<<endl;
            if ((now=='('&&s[i]!=')')||(now=='['&&s[i]!=']')||(now=='{'&&s[i]!='}'))
            {
            return false;
            }

        }
        
    }

    // 最后看看匹配完了没
    if (ans.size()!=0)
    {
        return false;
    }
    
    return true;
    
    



}

int main(){
    string s;
    getline(cin, s);
    bool ans = isValid(s);
    cout << ans << endl;
}