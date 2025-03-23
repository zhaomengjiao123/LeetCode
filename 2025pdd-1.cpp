#include <iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;



int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int x, y;
        cin>>x>>y;
        string str;
        cin>>str;
        int w =0, a=0,s=0,d=0;
        unordered_map<char, int> mp;

        for(int j=0;j<str.size();j++){
            if(str[j]=='W'){
                w++;
            }
            if(str[j]=='A'){
                a++;
            }
            if(str[j]=='S'){
                s++;
            }
            if(str[j]=='D'){
                d++;
            }
        }
        x=x-a+d;
        y=y+w-s;
        if(x==0&&y==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
   
}