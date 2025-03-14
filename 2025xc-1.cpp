#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


string getAns(string s){
    vector<string> sv;
    string ans="";
    int l = 1;
    int pos =0;
    while(pos<s.size()){
        ans = ans + s[pos]; // 首字母
        //计算要输出的字符数
        int length = min(l,(int)(s.size()-pos));
        // 更新位置
        pos = pos + length;
        l++;

    }
    return ans;
    

}

int main(){
    string s= "helloworld";
    string ans = getAns(s);
    cout<<ans<<endl;

}