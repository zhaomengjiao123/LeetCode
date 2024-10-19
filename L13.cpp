// 罗马数字转整数


#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<char,int> roman = {
    {'I',1},
    {'V',5},
    {'X',10},
    {'L',50},
    {'C',100},
    {'D',500},
    {'M',1000}
};

int romanToInt(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // 判断特殊情况
        if ((s[i]=='V'||s[i]=='X')&&i-1>=0&&s[i-1]=='I')
        {
            ans = ans + roman[s[i]]-roman[s[i-1]]-1;
        }else if ((s[i]=='L'||s[i]=='C')&&i-1>=0&&s[i-1]=='X')
        {
           ans =ans + roman[s[i]]-roman[s[i-1]]-10; 
        }else if((s[i]=='D'||s[i]=='M')&&i-1>=0&&s[i-1]=='C'){
            ans =ans + roman[s[i]]-roman[s[i-1]]-100;
        }else{
            ans = ans + roman[s[i]];
        }

        
        
    }

    return ans;
    
    
        
}

int main(){
    string s;
    getline(cin, s);

    int ans = romanToInt(s);

    cout << ans << endl;
}